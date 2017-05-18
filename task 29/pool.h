#include <iostream>
#include <condition_variable>
#include <queue>
#include <thread>
#include <memory>

using namespace std;

template <class T>
struct Data
{
	bool ready;
	Data() : ready(false) {};
	T data;
};


typedef std::function<void()> fn_type;
class Worker
{
	bool enabled;
	condition_variable cv;
	queue <fn_type> fQueue;
	mutex mutx;
	thread thred;

	void thread_fn();

public:
	void append(fn_type fn);
	size_t getTaskCount();
	bool isEmpty();
	Worker();
	~Worker();

};

class ThreadPool
{
	typedef shared_ptr<Worker> worker_ptr;

	worker_ptr getFreeWorker();
	vector <worker_ptr> workers;

public:
	template <class R, class FN, class... ARGS>
	shared_ptr<Data<R>> runAsync(FN fn, ARGS... args)
	{
		function<R()> rFn = bind(fn, args...);
		shared_ptr<Data<R>> pData(new Data<R>());
		fn_type fnT = [=]()
		{
			pData->data = rFn();
			pData->ready = true;
		};
		auto pWorker = getFreeWorker();
		pWorker->append(fnT);
		return pData;
	}

	template <class FN, class... ARGS>
	void runAsync(FN fn, ARGS... args)
	{
		auto pWorker = getFreeWorker();
		pWorker->append(bind(fn, args...));
	}

	ThreadPool(int threads);
};
