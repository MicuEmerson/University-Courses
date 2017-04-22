#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>


class Coat {

private:
	int size;
	std::string color;
	int price;
	int quantity;
	std::string photo;
	static int nr_instance;
	static int current_instance;

public:
	Coat() : size(0), color(""), price(0), quantity(0), photo("") {
		//nr_instance++;
		//current_instance++;
	};
	~Coat() { current_instance--; };
	Coat(Coat& x);
	Coat(int size, const std::string&, int price, int quantity, const std::string&);

	int get_price()			{ return price; }
	int get_size()			{ return size; }
	int get_quantity()		{ return quantity; }
	std::string get_color() { return color; }
	std::string get_photo() { return photo; }
	static int get_nr_instance();
	static int get_current_instance();

		
	void set_price(int p)		   { price = p; }
	void set_size(int s)		   { size = s; }
	void set_color(std::string c)  { color = c; }
	void set_photo(std::string ph) { photo = ph; }
	void set_quantity(int q)	   { quantity = q; }
	void see_photo();
	void print_coat();
};