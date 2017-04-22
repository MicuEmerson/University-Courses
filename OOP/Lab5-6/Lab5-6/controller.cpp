#include "controller.h"


//Function for adding an element to repo, return true if the element was succesfully added, else false
bool Controller::add_repo(Coat x)
{   
	return this->repo.add(x);
}

//Function for deleting an element to repo, return true if the element was succesfully deleted, else false
bool Controller::del_repo(Coat x)
{
	return this->repo.del(x);
}

//Function for updateing an element to repo, return true if the element was succesfully deleted, else false
bool Controller::update_repo(Coat x, Coat y)
{
	return this->repo.update(x, y);
}

//Function for printing the whole repository
void Controller::print_repo()
{
	return this->repo.print();
}

//Function for adding an element, return true if the element was succesfully added, else false
void Controller::add_bag(Coat x)
{
	this->bag.add(x);
}

//Function for getting the price of the bag repo
int Controller::get_price_bag()
{
    return this->bag.get_bagPrice();
}

//Function for printing the bag repo
void Controller::print_bag()
{
	this->bag.print();
}

//Returns a pointer to the first element of the repo.
Coat* Controller::getAll_repo()
{
	return this->repo.getAll();
}

//Returns the size of of main repository
int Controller::getSize_repo()
{
	return this->repo.getSize();
}
