#include "sortpack.h"

#ifndef VECTOR_INCLUDED
#define VECTOR_INCLUDED
#include <vector>
using namespace std;
#endif

//
// Sortpack help methods
//

// Sortpack constructor
sortpack::sortpack():arrSize(0) {
	arr = NULL;
	counterReset();
}

// Returns size of array
unsigned int sortpack::size() {
	return arrSize;
}

// Prints array to console
void sortpack::printElements() {
	arr->print();
	cout << endl;
}

// Fill array with numbers
void sortpack::fill(int size) {
	auto contents = new ArrayOfInt(size);
	arr = contents;
	arrSize = size;
}

// Swaps counter operations
void sortpack::counterIncrease() {
	++operationsCounter;
}
void sortpack::counterReset() {
	operationsCounter = 0;
}

//
// Sorting calls
//

void sortpack::bubble() {
	counterReset();
	bubbleSort();
}
void sortpack::select() {
	counterReset();
	selectSort();
}
void sortpack::insert() {
	counterReset();
	insertSort();
}
void sortpack::quick() {
	counterReset();
	quickSort();
}
void sortpack::shell() {
	counterReset();
	shellSort();
}

//
// Sorting algorithms
//

// Select sort on array
void sortpack::selectSort() {
	int firstUnsortedIndex = 0;
	
	while (firstUnsortedIndex < arrSize) {
		int minIndex = firstUnsortedIndex;

		for (int i = minIndex; i < arrSize; i++) {
			if ((*arr).operator[](i) < (*arr).operator[](minIndex)) {
				minIndex = i;
			}
		}

		if (minIndex > firstUnsortedIndex) {
			(*arr).operator[](minIndex).swap((*arr).operator[](firstUnsortedIndex));
			
			counterIncrease();
		}
		++firstUnsortedIndex;
	}
}

// Bubble sort on arrray
void sortpack::bubbleSort() {
	int lastIndex = arrSize - 1;
	for (int i = 0; i < lastIndex; i++) {
		for (int j = 0; j < lastIndex - i; j++) {
			SortedItems &cur = (*arr).operator[](j);
			SortedItems &next = (*arr).operator[](j + 1);
			if (next < cur) {
				cur.swap(next);
				counterIncrease();
			}
		}
	}
}

// Insert sort on array
void sortpack::insertSort(int start, int step) {
	if (start >= arrSize) throw outOfRangeEx(this);

	for (int i = start + step; i < arrSize; i += step) {
		for (int j = i; j > start; j -= step) {
			SortedItems &cur = (*arr).operator[](j);
			SortedItems &prev =(*arr).operator[](j - step);

			if (cur < prev) {
				cur.swap(prev);
				counterIncrease();
			}
			else break;
		}
	}
}

// Quick sort on arrray
void sortpack::quickSort(int l, int r) {
	if (r == -100) r = arrSize - 1;
	if (l >= r) return;

	int i = l, j = r;
	
	auto &s = (*arr).operator[]((l + r) / 2);

	while (i <= j) {

		while ((*arr).operator[](i) < s) i++;
		while (s < (*arr).operator[](j)) j--;
		
		if (i <= j) {
			(*arr).operator[](i).swap((*arr).operator[](j));
			i++; j--;

			counterIncrease();
		}
	}

	quickSort(l, j); quickSort(i, r);
}

// Shell sort on array
void sortpack::shellSort() {
	// Get steps for Shell sorting algorithm
	vector<int> steps; int step = arrSize;
	do {
		step /= 2;
		steps.push_back(step);
	} while (step != 1);
	
	// For every step value perform 'insert sort'
	// with this step starting from elements with
	// idexes 0, 1, ... , stepValue - 1
	unsigned long int numberOfSteps = steps.size();

	for (int currentStepNumber = 0; currentStepNumber < numberOfSteps; currentStepNumber++) {
		int stepValue = steps.at(currentStepNumber);
		for (int startIndex = 0; startIndex < stepValue; startIndex++) {
			insertSort(startIndex, stepValue);
		}
	}
}
