#include "pool.h"
#include <string>

double foo()
{
	return 14.5;
}

int sum(int a, int b)
{
	return a + b;
}
string myFn(int a, int b)
{
	string str = "String = " + to_string(a) + " " + to_string(b);
	return str;
}

int main()
{
	int n = 2;
	ThreadPool pool(n);

	//auto r1 = pool.runAsync<double>(&foo);
	//auto r2 = pool.runAsync<int>(&sum, 100, 54);
	//auto r3 = pool.runAsync<bool>([]() { return true; });
	//auto r4 = pool.runAsync<string>(myFn, 50, 20);

	//while (!r1->ready);
	//cout << r1->data << endl;
//	while (!r2->ready);	cout << r2->data << endl;
//	while (!r3->ready);
//	cout << r3->data << endl;
//	while (!r4->ready);
//	cout << r4->data << endl;
    return 0;
}
