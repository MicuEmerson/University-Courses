#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>
#include <sstream>
#include <vector>


class Coat {

private:
	int size;
	std::string color;
	int price;
	int quantity;
	std::string photo;

public:
	Coat() : size(0), color(""), price(0), quantity(0), photo("") {}
	Coat(int size, const std::string&, int price, int quantity, const std::string&);

	int get_price()			{ return price; }
	int get_size()			{ return size; }
	int get_quantity()		{ return quantity; }
	std::string get_color() { return color; }
	std::string get_photo() { return photo; }

		
	void set_price(int p)		   { price = p; }
	void set_size(int s)		   { size = s; }
	void set_color(std::string c)  { color = c; }
	void set_photo(std::string ph) { photo = ph; }
	void set_quantity(int q)	   { quantity = q; }
	void see_photo();
	void print_coat();

	bool operator==(Coat x);

	friend std::istream & operator>>(std::istream & is, Coat & x);
	friend std::ostream & operator<<(std::ostream & os, Coat & x);
		
};

