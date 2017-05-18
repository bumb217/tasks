#pragma once
#include <iostream>
#include <stdexcept>
#include "ListIterator.h"

using std::runtime_error;

template <typename T>
class Iterator;

template <typename T>
class List
{
	friend class Iterator<T>;
	List& operator =(const List&);
	List(const List&);
public:

	class BadList : public runtime_error
	{
	public:
		Iterator<T> BadIterator;
		BadList(const char* errMsg, const List* problemList)
			: runtime_error(errMsg),
			BadIterator(problemList)
		{}
	};

	List(T elem);
	//~List();
	virtual void push(T elem);
	virtual T head();
	virtual void pop();
	virtual Iterator<T> iterate();
	virtual void show();
protected:
	struct lnode
	{
		T _elem;
		lnode * _next;
		lnode() : _next(nullptr) {}
	};
	lnode * node;
};

template<typename T>
void List<T>::push(T elem)
{
	lnode* addNode = new lnode;
	addNode->_elem = elem;
	addNode->_next = node;
	node = addNode;
}

template<typename T>
T List<T>::head()
{
	return node->_elem;
}

template<typename T>
void List<T>::pop()
{
	if (node)
	{
		lnode* dellNode = node;
		node = node->_next;
		delete dellNode;
	}
	else throw BadList("List is empty", this);
}

template<typename T>
Iterator<T> List<T>::iterate()
{
	return Iterator<T>(this);
}

template<typename T>
void List<T>::show()
{
	for (auto it = Iterator<T>(this); !it.is_end(); it++)
		std::cout << *it << " ";
};

template<typename T>
List<T>::List(T elem)
{
	node = new lnode;
	node->_elem = elem;
}


/*template<typename T>
List<T>::~List()
{
	lnode *delptr;
	while (this->node) {
		delptr = this->node;
		this->node = this->node->_next;
		delete delptr;
	}
}*/

