#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

class MichealScott
{
	Node* Head;
	Node* Tail;
public:
	void push(int data);
	int pop();
	MichealScott();
	~MichealScott();
};
