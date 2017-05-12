#include "Strategy.h"

string CanWalk::move(){
	return "This unit can walk\n";
}

string NotWalk::move(){
	return "This unit can't walk\n";
}

string CanFly::move(){
	return "This unit can fly\n";
}

string NotFly::move(){
	return "This unit can't fly\n";
}

string MagicFly::move(){
	return "This unit can fly with magic\n";
}

Unit::Unit(string name,WalkStrategy* walk, FlyStrategy* fly){
	this->name = name;
	this->setStrategy(walk, fly);
}

string Unit::walkStrategy(){
	return this->walk->move();
}

string Unit::flyStrategy(){
	return this->fly->move();
}
