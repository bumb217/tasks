#include "stdafx.h"
#include "barrier.h"
void main()
{
	Graph gr;
	gr.print();

	gr.multFloyd();

	gr.print();

	system("pause");

}
