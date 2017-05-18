#pragma once
#include<stdexcept>

template <class T>
class node
{
public:
	T data;
	node<T>* next;
};

template <class T>
class Stack
{
private:
	node<T>* st;
	node<T>* top;
	size_t size;

public:
	Stack();
	Stack(const Stack<T>&);
	~Stack();

	void push(const T&);
	T pop();
	bool empty() const;
	
	size_t getSize() const;
	const node<T>* getTop() const;
	const node<T>* getSt() const;
};

template <class T>
Stack<T>::Stack()
{
	st = nullptr;
	size = 0;
	top = nullptr;
}

template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
	if (other.getSt() == nullptr)
	{
		st = nullptr;
		top = nullptr;
		size = 0;
		return;
	}

	st = new node<T>;
	st->data = other.st->data;
	st->next = nullptr;
	size = 1;

	node<T>* home = st;
	node<T>* alien = other.st->next;

	for (; alien != nullptr; home = home->next, alien = alien->next)
	{
		node<T>* newNode = new node<T>;
		newNode->data = alien->data;
		newNode->next = nullptr;
		home->next = newNode;
		size++;
	}
	top = home;
}

template <class T>
Stack<T>::~Stack()
{
	for(auto curr(st); curr != nullptr;)
	{
		node<T>* next_curr = curr->next;
		delete curr;
		curr = next_curr;
	}
}

template <class T>
void Stack<T>::push(const T& el)
{
	node<T>* newElem = new node<T>;
	newElem->data = el;
	newElem->next = nullptr;

	if (st == nullptr) st = newElem;

	else top->next = newElem;

	top = newElem;
	size++;
}

template <class T>
T Stack<T>::pop()
{
	T popped;
	if (size == 0) throw std::length_error("Stack is empty");

	else if (size == 1)
	{
		popped = top->data;
		delete st;
		st = nullptr;
		top = nullptr;
		size = 0;
	}
	else
	{
		node<T>* curr = st;
		for (; curr->next != top; curr = curr->next) {};
		popped = top->data;
		delete top;
		top = curr;
		top->next = nullptr;
		size--;
	}
	return popped;
}

template <class T>
bool Stack<T>::empty() const
{
	return size == 0;
}

template <class T>
size_t Stack<T>::getSize() const
{
	return size;
}

template <class T>
const node<T>* Stack<T>::getTop() const
{
	return top;
}

template <class T>
const node<T>* Stack<T>::getSt() const
{
	return st;
}
