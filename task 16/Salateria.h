#include <string>
using namespace std;

class Salad
{
protected:
	string description;
public:
	virtual string getDescription() {
		return description;
	};
	virtual double getPrice() = 0;
};

class GreenSalad : public Salad
{
public:
	GreenSalad() {
		description = "green salad";
	}

	double getPrice() {
		return 13.00;
	}
};

class PotatoSalad : public Salad
{
public:
	PotatoSalad() {
		description = "potato salad";
	}

	double getPrice() {
		return 20.00;
	}
};

class Decorator : public Salad
{
protected:
	Salad* salad;
public:
	Decorator(Salad* newSalad) {
		salad = newSalad;
	}

	string getDescription() {
		return salad->getDescription();
	}

	double getPrice() {
		return salad->getPrice();
	}

};

class CherryTomatoes : public Decorator
{
public:
	CherryTomatoes(Salad* newSalad) : Decorator(newSalad) {}

	string getDescription() {
		return salad->getDescription().append(", cherry tomatoes");
	}


	double getPrice() {
		return salad->getPrice() + 3;
	}
};

class Garlic : public Decorator
{
public:
	Garlic(Salad* newSalad) : Decorator(newSalad) {}

	string getDescription() {
		return salad->getDescription().append(", garlic");
	}

	double getPrice() {
		return salad->getPrice() + 2;
	}
};
