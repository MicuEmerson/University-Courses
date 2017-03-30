#pragma once
#include "dynamicArr.h"
#include "domain.h"

class ShopBag {

private:
	// Dynamic array for repository of shopbag
	DynamicVector <Coat> v;
	// Variable where we keep the total price of the elements from the shopbag.
	int price;

public:

	//costtructor
	ShopBag() : price(0) {}

	//Get an Coat object and add it to the
	void add(Coat x);

	//Print the whole bag repository
	void print();

	//Return the total price of items from the bag
	int get_bagPrice();

};