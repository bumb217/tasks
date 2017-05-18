#ifndef BOUNDED_STACK_AGGREGATING
#define BOUNDED_STACK_AGGREGATING

#include "Array.h"
#include "Stack.h"

#include <exception>

using namespace std;

template <class Elem>
class BoundedStackAgregatingArray: public IStack<Elem> {

	static const int bos = -1; 
	int _top;
	Array<Elem> stackArray;

public:
	
	explicit BoundedStackAgregatingArray(int size):stackArray(size), _top(bos){};
	
	bool empty() const {
		return (_top == bos);
	}

	bool full() const {
		return (_top == stackArray.size() - 1);
	}
	
	const Elem& top() const {
		if (empty()) throw BadStack();
		return stackArray[_top];
	}
	
	void pop() {
		if (empty()) throw BadStack();
		--_top;
	}

	void push(const Elem& value) {
		if (full()) throw BadStack();

		stackArray[++_top] = value;
	}
	
	int size() const {
		return stackArray.size();
	}

	
	class BadStack:public exception{
	public:
		void msg() {
			cout << what();
		}
	};
};

#endif
