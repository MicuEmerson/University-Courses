#include "book.h"

void Book::setAuthor(std::string a)
{
	this->author = a;
}

void Book::setName(std::string n)
{
	this->author = n;
}

std::string Book::getAuthor()
{
	return this->author;
}

std::string Book::getName()
{
	return this->name;
}

bool Book::operator==(Book a)
{
	return a.getAuthor() == author && a.getName() == name;
}

bool Book::operator<(Book a)
{
	if (author < a.getAuthor())
		return true;
	else if (author == a.getAuthor())
		return name < a.getName();
	else
		return false;
}

bool Book::operator>(Book a)
{
	if (author > a.getAuthor())
		return true;
	else if (author == a.getAuthor())
		return name > a.getName();
	else
		return false;
	
}
