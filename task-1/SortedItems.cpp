#include "SortedItems.h"

void IntToSort::print() {
	cout << val;
}
void IntToSort::swap(SortedItems &rval) {
	IntToSort &recievedVal = dynamic_cast<IntToSort&>(rval);
	std::swap(val, recievedVal.val);
}

bool IntToSort::operator<(const SortedItems &rval) const {
	IntToSort &rightValue = static_cast<IntToSort&>(const_cast<SortedItems&>(rval));

	return (val < rightValue.val);
}

//
// 'Get/Set' methods
//

int IntToSort::getVal() {
	return val;
}
void IntToSort::setVal(int nval) {
	val = nval;
}
