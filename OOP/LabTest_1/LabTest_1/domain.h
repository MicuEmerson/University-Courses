#pragma once
#include <string>
#include <iostream>
using namespace std;
class Project {

private:
	std::string name;
	std::string customer;
	int day;
	int mounth;
	int year;
	double cost;
	bool isDone;
public:

	Project() : name(""), customer(""), day(0), mounth(0), year(0), cost(0), isDone(false) {}
	Project(std::string name, std::string customer, int day, int mounth, int year, double cost, bool isDone);
	void print_project();
	std::string get_name() { return this->name; }
	std::string get_customer() { return this->customer; }
	bool get_isDone() { return this->isDone; }
	void set_isDone() { this->isDone = true; }
	double  get_cost() { return this->cost; }
	int get_day() { return this->day; }
	int get_mounth() { return this->mounth; }
	int get_year() { return this->year; }
};