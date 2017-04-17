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

std::string convert3(int x) {

	std::string res;
	while (x) {
		res += ((x % 10) + 48);
		x /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

static int first = 1;
void ShopBag::writeToFile()
{
	if (!first)
		return;

	first= 0;
	std::ofstream fout("bag.txt");
	std::string s;

	for (auto it : this->v) {
		s = convert3(it.get_size());
		s += "," + it.get_color();
		s += "," + convert3(it.get_price());
		s += "," + convert3(it.get_quantity());
		s += "," + it.get_photo() + "\n";
		fout << s;
	}
	fout.close();

	
}
