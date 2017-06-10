#pragma once
#include <string>

class Book {

private:
	std::string author;
	std::string name;

public:
	Book() : author(""), name(""){}
	Book(std::string a, std::string n) : author(a), name(n) {}

	void setAuthor(std::string a);
	void setName(std::string n);

	std::string getAuthor();
	std::string getName();

	bool operator ==(Book a);
	bool operator <(Book a);
	bool operator >(Book a);
	
};