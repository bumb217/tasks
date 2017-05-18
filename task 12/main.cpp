#include "list.h"
#include <omp.h>

int main()
{
	MichealScott querry;
#pragma omp parallel for omp_get_num_threads(200)
	for (int i = 1; i < 10000; i++)
		querry.push(i);
	for (int i = 1; i < 10004; i++)
	{
		int n = querry.pop();
		if (n >= 0)
			cout << n << " ";
	}
	return 0;
}
