#include "domain.h"

Project::Project(std::string name, std::string customer, int day, int mounth, int year, double cost, bool isDone)
{
	this->name = name;
	this->customer = customer;
	this->day = day;
	this->mounth = mounth;
	this->year = year;
	this->cost = cost;
	this->isDone = isDone;
}

void Project::print_project()
{
	cout << "Name: " << this->name << " ,Customer: " << this->customer << " ,Day: " << this->day << ", Mounth" << this->mounth << ", Year:" << this->year << ", cost:" << this->cost << ", isDone: " << this->isDone << endl;
}
