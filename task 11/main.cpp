#include "BoundedStackDerivedFromArray.h"
#include "BoundedStackAggregatingArray.h"
#include "PeekBackStack.h"

int main()
{
	PeekbackStack<int> myStack(5);

	myStack.push(0);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);

	cout << myStack.peekback(2, 1) << endl;
	return 0;
}
