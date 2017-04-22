#include "repository.h"

bool Repository::add(Coat x)
{   
	if (this->find(x) != -1)
		return false;

	this->v.add(x);
	return true;
}

int Repository::find(Coat x)
{   
	Coat *vec = this->v.getAll();
	
	for (int i = 0; i < this->v.getSize(); i++) {
		Coat y = vec[i];
		if (x.get_color() == y.get_color() && x.get_size() == y.get_size())
			return i;
	}
	return -1;
}

bool Repository::del(Coat x)
{   
	int pos = this->find(x);
	if (pos == -1)
		return false;

	//this->v.del(pos);
	
	this->v - x;
	return true;
}

bool Repository::update(Coat x, Coat y)
{   
	if(this->find(x) == -1)
		return false;
	this->del(x);
	this->add(y);
	return true;
}


void Repository::print()
{   
	Coat *vec = this->v.getAll();
	
	for (int i = 0; i < this->v.getSize(); i++) {
		Coat x = vec[i];
		x.print_coat();
	}
}

Coat* Repository::getAll()
{
	return this->v.getAll();
}

int Repository::getSize()
{
	return this->v.getSize();
}

bool Repository::operator==(Coat x)
{
	return false;
}


