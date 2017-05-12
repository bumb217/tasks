#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Observer //observer interface
{
public:
	virtual void update(const vector<string>& press) = 0;
};

class Subject //subject interface
{
	virtual void addObserver(Observer& o) = 0;
	virtual void deleteObserver(Observer& o) = 0;
	virtual void notifyObservers() = 0;
};

class Post : public Subject
{
protected:
	unordered_set<Observer*> observers;
	vector<string> press_available;

public:
	Post() {}

	unordered_set<Observer*> getObservers() {
		return observers;
	}

	vector<string> getPress() {
		return press_available;
	}

	void addObserver(Observer& o) {
		observers.insert(&o);
	}

	void deleteObserver(Observer& o) {
		observers.erase(&o);
	}

	void notifyObservers() {
		for (Observer* x : observers) {
			x->update(press_available);
		}
	}

	void getNewPress(const vector<string>& new_press) {

		press_available = new_press;
		notifyObservers();
	}
};

class Reader : public Observer
{
	string name;
	unordered_set<string> subscribed;
	string result;

public:
	Reader(string n, unordered_set<string> s){ name = n; subscribed = s; }

	void update(const vector<string>& press) {
		result = name + ": Got a new copy of: ";
		int count_of_new(0);
		for (size_t i(0); i < press.size(); i++) {
			std::unordered_set<std::string>::const_iterator it = subscribed.find(press[i]);
			if (it != subscribed.end())
			{
				result = result  + press[i] + " ";
				count_of_new++;
			}
		}
		if (count_of_new == 0){
			result = name + ": No new copies for me this time..";
		}
	}

	string getTodaysResult(){
		return result;
	}
};
