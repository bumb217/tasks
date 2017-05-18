#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>

using namespace std;

template <class Elem>
class Array {
public:
	Array (int sz = defaultArraySize):_size(sz) {
		ia = new Elem[sz];	
	}

	Array (const Array& src) {
		init(src.size(), src.ia);
	}

	~Array() {
		delete []ia;
	}
	bool operator== (const Array& another) const {
		if (_size != another._size) return false;
		for (int i = 0; i < _size; i++) {
			if (ia[i] != another.ia[i]) return false;
		}

		return true;
	}
	bool operator!= (const Array& another) const {
		return !(operator==(another));
	}

	Array& operator= (const Array& src) {
		init(src.size(), src.ia);
	}
	
	Elem& operator[] (int index) {
		if (index >= _size || index < 0) throw (out_of_range);
		return ia[index];
	}
	Elem& operator[] (int index) const {
		if (index >= _size || index < 0) throw (out_of_range);
		return ia[index];
	}

	int size() const {
		return _size;	
	};
	
private:
	int _size;		
	Elem *ia;		

	void init(int sz, Elem* sourceArray) {
		delete []ia;
		ia = new Elem[sz];
		_size = sz;

		for (int i = 0; i < sz; i++) {
			ia[i] = sourceArray[i];
		}
	}

	static const int defaultArraySize;
};

template <class Elem>
const int Array<Elem>::defaultArraySize = 256;

#endif
