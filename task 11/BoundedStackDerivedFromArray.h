#ifndef BOUNDED_STACK_DERIVED
#define BOUNDED_STACK_DERIVED

#include "ProtectedArray.h"
#include "Stack.h"
#include <exception>

using namespace std;

template <class Elem>
class BoundedStackDerivedFromArray: protected ProtectedArray<Elem>, public IStack<Elem> 
{

	static const int bos = -1; 

protected:
	int _top;

public:
	explicit BoundedStackDerivedFromArray(int size): ProtectedArray(size), _top(bos){}

	bool empty() const 
	{
		return (_top == bos);
	}
	
	bool full() const 
	{
		return (_top == size() - 1);
	}

	const Elem& top() const
	{
		if (empty()) throw BadStack();
		return ia[_top];
	}
	
	void pop()
	{
		if (empty()) throw BadStack();
		--_top;
	}
	
	void push(const Elem& value) 
	{
		if (full()) throw BadStack();
		ia[++_top] = value;
	}

	class BadStack:public exception
	{
	public:
		void msg() 
		{
			cout << what();
		}
	};
};

#endif
