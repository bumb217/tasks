#ifndef SortedItems_INCLUDED
#define SortedItems_INCLUDED

#include <iostream>
using namespace std;

// Interface for SortedItems objects
class SortedItems {
public:
	virtual bool operator<(const SortedItems &rval) const = 0;	// Comparison operator
	virtual void swap(SortedItems &rval) = 0;					// Swap method
	virtual void print() = 0;								// Console output
};

// SortedItems Integer
class IntToSort: public SortedItems {
	int val;
public:
	IntToSort(const int &nval = 0):val(nval) {}		// Constructor

	void print();									// Console output
	void swap(SortedItems &another);				// Swap
	
	bool operator<(const SortedItems &rval) const;	// Comparison operator

	int getVal();									// Get value
	void setVal(int nval);							// Set value
};
#endif
