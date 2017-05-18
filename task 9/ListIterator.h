#pragma once

#include "List.h"

template <typename T>
class Iterator
{
	typename List<T>::lnode*  _first;
	typename List<T>::lnode* _current;
public:
	Iterator(const List<T>* source)                                          
		: _first(source->node),
		_current(source->node)
	{}

	void operator++(int);                                                    
	void operator++();                                                      
	bool operator != (Iterator right);
	bool operator == (Iterator right);
	T& operator *();                                                        

	void to_start();
	bool is_start();
	bool is_end();
};

/*template <typename T>
void Iterator<T>::operator++(int)
{
	if (_current)
		_current = _current->_next;
	else
		throw runtime_error("iterator can not  be incremented");
}
*/
template <typename T>
void Iterator<T>::operator++()
{
	if (_current)
		_current = _current->_next;
	else
		throw runtime_error("iterator can not  be incremented");
}

template <typename T>
T& Iterator<T>::operator *()
{
	if (_current)
		return _current->_elem;
	else
		throw runtime_error("iterator can not  be dereferenced");
}

template <typename T>
void Iterator<T>::to_start()
{
	_current = _first;
}

template <typename T>
bool Iterator<T>::is_start()
{
	return (_first == _current);
}

template <typename T>
bool Iterator<T>::is_end()
{
	if (_current)
	return (_current->_next == _first);
	else return true;
}

template <typename T>
bool Iterator<T>::operator != (Iterator right)
{
	return (_first != right._first || _current != right._current);
}

template <typename T>
bool Iterator<T>::operator == (Iterator right)
{
	return (_first == right._first && _current == right._current);
}
