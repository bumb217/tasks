#include "barrier.h"

Barrier::Barrier(int maxCount)
{
	maxCountOfThreads = maxCount;
	waitCounter.store(0);
	allAreWaiting = CreateEvent(NULL, TRUE, FALSE, NULL);
}

void Barrier::end()
{
	ResetEvent(allAreWaiting);
	int readyThreads = waitCounter++;
	if (readyThreads >= maxCountOfThreads - 1)
	{
		waitCounter.store(0);
		SetEvent(allAreWaiting);
	}
	else
		WaitForSingleObject(allAreWaiting, INFINITE);
}


Graph::Graph()
{
	this->readFromFile();
}

void Graph::readFromFile()
{
	ifstream inputFileStream("graph.txt");
	int count, a;
	inputFileStream >> count;
	this->vertexCount = count;
	matrix = new int*[count];

	for (unsigned i = 0; i < count; i++)
	{
		matrix[i] = new int[count];
		for (unsigned j = 0; j < count; j++)
		{
			inputFileStream >> a;
			if (a == 0)
				a = 1000000;
			matrix[i][j] = a;
		}
	}
	inputFileStream.close();
}

void Graph::print()
{
	for (unsigned i = 0; i < vertexCount; i++)
	{
		for (unsigned j = 0; j < vertexCount; j++)
		{
			if (matrix[i][j] == 1000000)
				cout << "0 ";
			else
				cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

DWORD WINAPI Graph::floydAlgorythm(params *par)
{
	int i = par->rowCount;

	SetEvent(par->threadInitEnd);

	for (unsigned k = 0; k < vertexCount; k++)
	{
		for (unsigned j = 0; j < vertexCount; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
		}
		par->threadBarrier->end();
	}

	return 0;
}
DWORD WINAPI Graph::floydWrapper(CONST LPVOID args)
{
	params *par = (params*)args;
	Graph *curGraph = par->graph;
	curGraph->floydAlgorythm(par);
	return 0;
}

void Graph::multFloyd()
{
	params par(this, vertexCount);

	HANDLE *hThreads = new HANDLE[vertexCount];
	for (unsigned i = 0; i < vertexCount; i++)
	{
		par.rowCount = i;
		ResetEvent(par.threadInitEnd);
		hThreads[i] = CreateThread(NULL, 0, &floydWrapper, &par, 0, NULL);
		WaitForSingleObject(par.threadInitEnd, INFINITE);
	}
	WaitForMultipleObjects(vertexCount, hThreads, TRUE, INFINITE);

	for (unsigned i = 0; i < vertexCount; i++)
	{
		CloseHandle(hThreads[i]);
	}
}
