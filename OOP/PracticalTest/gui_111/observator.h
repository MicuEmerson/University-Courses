#pragma once
#include <algorithm>
#include <vector>

class Observator {

public:
	virtual ~Observator() {}
	virtual void update() = 0;
};

class Observabil {

private:
	std::vector<Observator*> v;
public:
	virtual ~Observabil() {}
	void addObs(Observator* x) { v.push_back(x); }
	void removeObs(Observator * x) {
		v.erase(std::remove(v.begin(), v.end(), x));
	}
	void notify() {
		for (auto it : v)
			it->update();
	}
};