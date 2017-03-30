#include "shopBag.h"

void ShopBag::add(Coat x)
{  
	this->v.add(x);
	this->price += x.get_price();
}

void ShopBag::print()
{
	Coat *vec = this->v.getAll();

	for (int i = 0; i < this->v.getSize(); i++) {
		std::cout << "Size: " << vec[i].get_size() << " Color: " << vec[i].get_color() << " Price: " << vec[i].get_price() << '\n';
	}
}

int ShopBag::get_bagPrice()
{
	return this->price;
}
