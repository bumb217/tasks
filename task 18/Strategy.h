#include <bits/stdc++.h>
using namespace std;

class WalkStrategy{
public:
	virtual string move() = 0;
};

class CanWalk :public WalkStrategy{
public:
	string move();
};

class NotWalk :public WalkStrategy{
public:
	string move();
};

class FlyStrategy{
public:
	virtual string move() = 0;
};

class CanFly :public FlyStrategy{
public:
	string move();
};

class NotFly :public FlyStrategy{
public:
	string move();
};

class MagicFly :public FlyStrategy{
public:
	string move();
};

class FantasyUnit{
protected:
	WalkStrategy* walk;
	FlyStrategy* fly;
public:
	virtual string walkStrategy() = 0;
	virtual string flyStrategy() = 0;
	void setStrategy(WalkStrategy* walk, FlyStrategy* fly){
		this->walk = walk;
		this->fly = fly;
	};
};

class Unit :public FantasyUnit{
public:
	string name;
	Unit(string name, WalkStrategy* walk, FlyStrategy* fly);
	string walkStrategy();
	string flyStrategy();
};
