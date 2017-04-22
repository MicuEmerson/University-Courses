#include "domain.h"
#include <shellapi.h>

int Coat::nr_instance = 0;
int Coat::current_instance = 0;

Coat::Coat(int size, const std::string& color, int price, int quantity, const std::string& photo)
{
	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->photo = photo;
	nr_instance++;
	current_instance++;
}

Coat::Coat(Coat& x) {

	this->color = x.color;
	this->photo = x.photo;
	this->quantity = x.quantity;
	this->price = x.price;
	this->size = x.size;
	nr_instance++;
	current_instance++;

}


int Coat::get_nr_instance()
{
	return nr_instance;
}

int Coat::get_current_instance()
{
	return current_instance;
}


void Coat::print_coat()
{
	std::cout << "Size: " << this->size << " Color: " << this->color << " Price: " << this->price << " Quantity: " << this->quantity <<  '\n';
}

void Coat::see_photo()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->get_photo().c_str(), NULL, SW_SHOWMAXIMIZED);
	
}

