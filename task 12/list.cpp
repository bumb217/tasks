#include "list.h"

MichealScott::MichealScott()
{
	Head = new Node;
	Head->next = NULL;
	Head->data = 0;
	Tail = Head;
}

void MichealScott::push(int data)
{
	Node* tmp = new Node;
	tmp->next = NULL;
	tmp->data = data;
	while (Tail->next)
		Tail = Tail->next;
	Tail->next = tmp;
	Tail = tmp;
}

int MichealScott::pop()
{
	if (Head == Tail)
	{
		if (Head->next)
		{
			while (Tail->next)
				Tail = Tail->next;
		}
		else
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
	}
	Node* ptr = Head;
	Head = Head->next;
	delete ptr;
	return Head->data;
}

MichealScott::~MichealScott()
{
	while (Head->next)
	{
		Node* ptr = Head;
		Head = Head->next;
		delete ptr;
	}
}
