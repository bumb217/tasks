#include <iostream>
#include "Lists.h"
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int n = 40;
	DoubleSidedList <char> first('l');
	for (int i = 1; i < n; i++)
	{
		char temp = 'a'+ rand() % 25;
		first.push(temp);
	}
	first.show();
	cout << "\n";

	CyclicList<int> second(n);

	for (int i = 1; i < 20; i++)
	{
		int temp = rand() % 100;
		second.push(temp);
	}
	second.show();
	cout << "\n";
    return 0;

}
