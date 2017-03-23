#ifndef SortedItems_ARRAY_INCLUDED
#define SortedItems_ARRAY_INCLUDED

#include "SortedItems.h"

//
// Interface for array of SortedItemss
//

// Abstract array
class ArrayOfItems {
public:
	virtual SortedItems& operator[] (const int &index) = 0;	// Indexing
	virtual void print() = 0;								// Console print
	virtual void fill(int size) = 0;						// Fill with some elements
};

// Array of integers
class ArrayOfInt: virtual public ArrayOfItems {
	IntToSort *items;		// Contents
	int size;				// Size of contents
public:
	ArrayOfInt(int nsize);	// ctor
	~ArrayOfInt();			// dtor

	SortedItems& operator[] (const int &index);	// Indexing
	void print();								// Console output
	void fill(int size);						// Fill with numbers
};
#endif
