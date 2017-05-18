#pragma once

#include "ListIterator.h"
#include "List.h"

template <typename T>
class CyclicList : virtual public List<T>
{
public:
	CyclicList(T elem) : List(elem)
	{
		node = new lnode;
		node->_elem = elem;
		node->_next = node;
	};
	virtual void push(T elem);
	virtual void pop();
};

template <typename T>
class DoubleSidedList : virtual public List<T>
{
	lnode * prev;
public:
	DoubleSidedList(T elem) :List(elem) { prev = node; };
	virtual void push(T elem);
};

template <typename T>
class CyclicDoubleSidedList : public DoubleSidedList<T>, public CyclicList<T>
{
public:
	CyclicDoubleSidedList(T elem) : CyclicList(elem), DoubleSidedList(elem) {};
	virtual void push(T elem);
	virtual void pop();
};

template<typename T>
inline void CyclicList<T>::push(T elem)
{
	lnode* addNode = new lnode;
	addNode->_elem = elem;
	addNode->_next = node->_next;
	node->_next = addNode;
}

template<typename T>
inline void CyclicList<T>::pop()
{
	if (node)
	{
		lnode* dellNode = node->_next;
		node->_next = node->_next->_next;
		delete dellNode;
	}
	else throw BadList("Empty List!", this);
}

template<typename T>
inline void DoubleSidedList<T>::push(T elem)
{
	lnode* addNode = new lnode;
	addNode->_elem = elem;
	prev->_next = addNode;
	prev = addNode;
}

template<typename T>
inline void CyclicDoubleSidedList<T>::push(T elem)
{
	lnode* addNode = new lnode;
	addNode->_elem = elem;
	addNode->_next = node;
	node = addNode;
	prev->_next = addNode;
}

template<typename T>
inline void CyclicDoubleSidedList<T>::pop()
{
	if (node)
	{
		lnode* dellNode = node;
		node = node->_next;
		prev->_next = node;
		delete dellNode;
	}
	else throw BadList("Empty List!", this);
}
