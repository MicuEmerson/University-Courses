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

