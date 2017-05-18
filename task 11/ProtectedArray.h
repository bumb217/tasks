#ifndef PROTECTED_ARRAY_H
#define PROTECTED_ARRAY_H

#include <iostream>
#include <exception>

using namespace std;

template <class Elem>
class ProtectedArray {
public:
	ProtectedArray (int sz = defaultProtectedArraySize):_size(sz) {
		ia = new Elem[sz];	
	}

	ProtectedArray (const ProtectedArray& src) {
		init(src.size(), src.ia);
	}

	~ProtectedArray() {
		delete []ia;
	}

	bool operator== (const ProtectedArray& another) const {
		if (_size != another._size) return false;
		for (int i = 0; i < _size; i++) {
			if (ia[i] != another.ia[i]) return false;
		}

		return true;
	}
	bool operator!= (const ProtectedArray& another) const {
		return !(operator==(another));
	}

	ProtectedArray& operator= (const ProtectedArray& src) {
		init(src.size(), src.ia);
		return *this;
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
	
protected:
	Elem *ia;		

private:
	int _size;		
	void init(int sz, Elem* sourceArray) {
		delete []ia;
		ia = new Elem[sz];
		_size = sz;

		for (int i = 0; i < sz; i++) {
			ia[i] = sourceArray[i];
		}
	}

	static const int defaultProtectedArraySize;
};

template <class Elem>
const int ProtectedArray<Elem>::defaultProtectedArraySize = 256;

#endif
