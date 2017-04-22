#pragma once
#include <vector>
#include "domain.h"
#include <fstream>

class ShopBag {

private:
	
	std::vector <Coat> v;
	// Variable where we keep the total price of the elements from the shopbag.
	int price;

public:

	ShopBag() : price(0) {}
	
	void add(Coat x);
	void print();
	int get_bagPrice();

};