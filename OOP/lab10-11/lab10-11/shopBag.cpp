#include "shopBag.h"

void ShopBag::add(Coat x)
{  
	this->v.push_back(x);
	this->price += x.get_price();
}

void ShopBag::print()
{
	for(auto it: this->v) 
		std::cout << "Size: " << it.get_size() << " Color: " << it.get_color() << " Price: " << it.get_price() << '\n';
}

int ShopBag::get_bagPrice()
{
	return this->price;
}
