#include <iostream>
#include <gtest\gtest.h>
#include "Salateria.h"
using namespace std;

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}
