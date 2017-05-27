#include "domain.h"

Coat::Coat(int size, const std::string& color, int price, int quantity, const std::string& photo)
{
	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->photo = photo;
}


void Coat::print_coat()
{
	std::cout << "Size: " << this->size << " Color: " << this->color << " Price: " << this->price << " Quantity: " << this->quantity <<  '\n';
}


bool Coat::operator==(Coat x)
{
	if (this->color == x.get_color() && this->size == x.get_size())
		return true;
	return false;
}


void Coat::see_photo()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->get_photo().c_str(), NULL, SW_SHOWMAXIMIZED);	
}


std::vector<std::string> tokenize(std::string s, char del) {

	std::stringstream ss(s);
	std::string x;
	std::vector<std::string> rez;

	while (getline(ss, x, del))
		rez.push_back(x);
	
	return rez;
}


std::istream & operator>>(std::istream & is, Coat & x)
{
	std::string s;
	getline(is, s);
	
	std::vector<std::string> rez = tokenize(s, ',');
	if (rez.size() != 5) return is;
	x.size = atoi(rez[0].c_str());
	x.color = rez[1];
	x.price = atoi(rez[2].c_str());
	x.quantity = atoi(rez[3].c_str());
	x.photo = rez[4];

	return is;
}


std::ostream & operator<<(std::ostream & os, Coat & x)
{
	os << x.size << "," << x.color << "," << x.price << "," << x.quantity << "," << x.photo << '\n';
	return os;
}
