#pragma once
#include <vector>
#include "domain.h"
#include <fstream>
#include <Windows.h>
#include <shellapi.h>

class ShopBag {

protected:
	
	std::vector <Coat> v;
	int price;

public:

	ShopBag() : price(0) {}
	
	void add(Coat x);
	void print();
	int get_bagPrice();
	virtual void writeToFile_bag() = 0;
	virtual void openThings() = 0;
	std::vector<Coat> & getAll_B() { return this->v; }
	
};