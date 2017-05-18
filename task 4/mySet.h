#pragma once
#include <vector>
#include <list>
using namespace std;

template <typename T>
class SetImplementor
{
public:
	virtual void insert(T) = 0;
	virtual void erase(T) = 0;
	virtual bool belongs(T) = 0;
	virtual size_t size() = 0;
};

template <typename T>
class VectorToSetAdapter : public SetImplementor<T>
{
	vector<T> cont;
public:
	void insert(T val)
	{
		cont.push_back(val);
	}
	void erase(T val)
	{
		cont.erase(find(cont.begin(), cont.end(), val));
	}
	bool belongs(T val)
	{
		return (find(cont.begin(), cont.end(), val) != cont.end());
	}
	size_t size()
	{
		return cont.size();
	}
};

template <typename T>
class ListToSetAdapter : public SetImplementor<T>
{
	list<T> cont;
public:
	void insert(T val)
	{
		cont.push_back(val);
	}
	void erase(T val)
	{
		cont.erase(find(cont.begin(), cont.end(), val));
	}
	bool belongs(T val)
	{
		return (find(cont.begin(), cont.end(), val) != cont.end());
	}
	size_t size()
	{
		return cont.size();
	}
};


template <typename T>
class Set
{
protected:
	SetImplementor<T>* imp;
public:
	Set(SetImplementor<T>* src) : imp(src) {}
	virtual bool insert(T val)
	{
		if (!belongs(val))
		{
			imp->insert(val);
			return true;
		}
		else return false;
	}
	virtual bool erase(T val)
	{
		if (belongs(val))
		{
			imp->erase(val);
			return true;
		}
		else return false;
	}
	virtual bool belongs(T val) { return imp->belongs(val); }
	virtual size_t size() { return imp->size(); }
};
