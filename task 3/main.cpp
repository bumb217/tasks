#include "skiplist.h"

int main()
{
	List<int> list;
	srand(time(NULL));
#pragma omp parallel for num_threads(4)
	for (int i = 0; i < 50; i++)
	{
		int a = rand() % 200;
		cout << a << " ";
		list.push(a);
	}
	int s = list.Size();
	cout << s;
	char p;
	cin >> p;
#pragma omp parallel for num_threads(4)
	for (int i = 0; i < s; i++)
	{
		cout << list.get(i) << " ";
	}
	cin >> p;
#pragma omp parallel for num_threads(4)
	for (int i = 0; i < s; i++)
	{
		string st = to_string(list.get(0));
		cout << st << " ";
		list.erase(0);
	}
	s = list.Size();
	cout << "\n";
	cin >> p;
    return 0;
}
