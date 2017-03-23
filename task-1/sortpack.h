#ifndef SORTPACK_INCLUDED
#define SORTPACK_INCLUDED

//
// Sortpack uses 'SortedItems' interface
//

#include "ArrayOfItems.h"

class sortpack {
	ArrayOfItems *arr;							// Pointer to array

	SortedItems & at(const int &index);			// Returns reference to element of array
	unsigned int arrSize;						// Holds size of array


	unsigned int operationsCounter;

	void counterIncrease();
	void counterReset();

	void quickSort(int l = 0, int r = -100);		// Quick sort
	void shellSort();								// Shell sort
	void selectSort();								// Select sort
	void bubbleSort();								// Bubble sort
	void insertSort(int start = 0, int step = 1);	// Insert sort

public:

	sortpack();									// Constructor

	void printElements();						// Elements to console
	void fill(int size);						// Fill with some elements

	void quick();								// Quick sort call
	void shell();								// Shell sort call
	void select();								// Select sort call
	void bubble();								// Bubble sort call
	void insert();								// Insert sort call

	unsigned int size();						// Get size of array
	unsigned int getCounter();					// Returns counter

	

	//
	// Exception classes
	//

	class outOfRangeEx: public exception {
		void *src;
	public:
		outOfRangeEx(void *source):src(source) {};
		void printMessage() {
			cout << "Out of range exception at: " << src << endl;
		}
	};
};

#endif
