#pragma once
#include <string>
#include <qdebug.h>
class Programmer {

private:
	std::string name;
	int nrRevised;
	int total;
public:
	Programmer(std::string _name, int n, int t) : name(_name), nrRevised(n), total(t) {}

	auto getName() { return name; }
	auto getNrFields() { return nrRevised; }
	auto getTotal() { return total; }
	void setTotal(int x) { 
		qDebug() << "AAA";
		nrRevised = x; }
	
};