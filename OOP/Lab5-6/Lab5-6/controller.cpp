#include "controller.h"

bool Controller::add_repo(Coat x)
{   
	return this->repo.add(x);
}

bool Controller::del_repo(Coat x)
{
	return this->repo.del(x);
}

bool Controller::update_repo(Coat x, Coat y)
{
	return this->repo.update(x, y);
}

void Controller::print_repo()
{
	return this->repo.print();
}

void Controller::add_bag(Coat x)
{
	this->bag.add(x);
}

int Controller::get_price_bag()
{
    return this->bag.get_bagPrice();
}

void Controller::print_bag()
{
	this->bag.print();
}


Coat* Controller::getAll_repo()
{
	return this->repo.getAll();
}

int Controller::getSize_repo()
{
	return this->repo.getSize();
}
