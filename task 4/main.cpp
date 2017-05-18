#include "mySet.h"
#include <iostream>
#include <time.h>

int main()
{
	srand(time(NULL));
	int n = 20;
	Set <char> set(new ListToSetAdapter<char>);
	for (int i = 0; i < n; i++)
	{
		char temp;
		temp = 'a' + rand() % 20;
		set.insert(temp);
		cout << temp << " ";
	}
	cout << "\n\n";
	for (int i = 0; i < n / 2; i++)
	{
		char temp;
		temp = 'a' + rand() % 20;
		set.erase(temp);
		cout << temp << " ";
	}
	cout << "\n";
	for (int i = 0; i < 20; i++)
		cout << char('a' + i) << " : " << boolalpha << set.belongs('a' + i) << "  ";



	Set<int> mySet(new VectorToSetAdapter<int>);

	for (int i = 0; i < n; i++)
	{
		char temp;
		int t = rand() % 20;
		temp = 'a' + rand() % 100;
		mySet.insert(t);
		cout << t << " ";
	}
	cout << "\n\n";
	for (int i = 0; i < n/2; i++)
	{
		char temp;
		int t = rand() % 20;
		temp = 'a' + rand() % 25;
		mySet.erase(t);
		cout << t << " ";
	}
	cout << "\n";
	for (int i = 0; i < 20; i++)
		cout << i << " : " << boolalpha << mySet.belongs(i) << "  ";
	return 0;
}
