#include "pool.h"


Worker::Worker() :enabled(true), fQueue(), thred(&Worker::thread_fn, this) {};

Worker::~Worker()
{
	enabled = false;
	cv.notify_one();
	thred.join();
}

void Worker::append(fn_type fn)
{
	unique_lock <mutex> locker(mutx);
	fQueue.push(fn);
	cv.notify_one();
}

size_t Worker::getTaskCount()
{
	unique_lock <mutex> locker(mutx);
	return fQueue.size();
}

bool Worker::isEmpty()
{
	unique_lock <mutex> locker(mutx);
	return fQueue.empty();
}

void Worker::thread_fn()
{
	while (enabled)
	{
		unique_lock <mutex> locker(mutx);

		//wait for free thread
		cv.wait(locker, [&]() {return !fQueue.empty() || !enabled; });

		while (!fQueue.empty())
		{
			fn_type fn = fQueue.front();
			locker.unlock();
			fn();
			locker.lock();
			fQueue.pop();
		}
	}
}


ThreadPool::ThreadPool(int threads)
{
	/*if (threads == 0)
		threads = 1;
	for (int i = 0; i < threads; i++)
	{
		worker_ptr pWorker(new Worker);
		workers.push_back(pWorker);
	}*/
}

ThreadPool::worker_ptr ThreadPool::getFreeWorker()
{
	worker_ptr pWorker;
	size_t minTasks = UINT32_MAX;
	for (auto &it : workers)
	{
		if (it->isEmpty())
		{
			return it;
		}
		else if (minTasks > it->getTaskCount())
		{
			minTasks = it->getTaskCount();
			pWorker = it;
		}
	}
	return pWorker;
}
