#include "ArrayOfItems.h"

// ArrayOfInt constructors and destructors

ArrayOfInt::ArrayOfInt(int nsize):size(nsize){
	items = new IntToSort[nsize];
	fill(nsize);
}
ArrayOfInt::~ArrayOfInt() {
	delete [] items;
}

// Indexing operator
SortedItems &ArrayOfInt::operator[](const int &index) {
	return items[index];
}

// Print method
void ArrayOfInt::print() {
	for (int i = 0; i < size; i++) {
		items[i].print(); cout << " ";
	}
}

// Fill method
void ArrayOfInt::fill(int size) {
	for (int i = 0; i < size; i++) 
		items[i] = IntToSort(rand()%101);
}
