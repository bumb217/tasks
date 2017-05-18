#include <iostream>
#include <fstream>
#include <windows.h>
#include <atomic>

using namespace std;

class Barrier 
{
private:
	atomic_int waitCounter;
	LONG maxCountOfThreads;

public:
	HANDLE allAreWaiting;
	Barrier(int maxCount);
	void end();
};

class Graph
{
private:
	int **matrix;
	int vertexCount;
	void readFromFile(); 

	struct params 
	{
		int rowCount;
		Graph *graph;
		HANDLE threadInitEnd; 
		Barrier *threadBarrier;
		params(Graph *gr, int barrierMaxCount)
		{
			threadBarrier = new Barrier(barrierMaxCount);
			graph = gr;
			threadInitEnd = CreateEvent(NULL, TRUE, FALSE, NULL);
		}
	};
	DWORD WINAPI floydAlgorythm(params *par); 
	static DWORD WINAPI floydWrapper(CONST LPVOID args);

public:
	Graph();
	void print(); 
	void multFloyd();
};
