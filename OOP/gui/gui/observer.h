#pragma once
#include <vector>
#include <algorithm>

class Observer {

public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Observable {
	
private:
	std::vector<Observer*> observers;
public:
	virtual ~Observable(){}

	void addObserver(Observer* x) { this->observers.push_back(x); }
	void removeObserver(Observer* x) { std::remove(observers.begin(), observers.end(), x); }

	void notify() {
		for (auto it : observers)
			it->update();
	}
};