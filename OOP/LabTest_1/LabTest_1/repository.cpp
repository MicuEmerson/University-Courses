#include "repository.h"

bool Repository::find(Project x)
{
	for (auto it : v)
		if (it.get_customer() == x.get_customer() && it.get_name() == x.get_name())
			return true;
	return false;
}

bool Repository::add(Project x)
{  
	if (this->find(x))
		return false;
	this->v.push_back(x);
	return true;
}

bool Repository::mark(Project x)
{
	for (auto &it : v)
		if (it.get_customer() == x.get_customer() && it.get_name() == x.get_name()) {
			if (it.get_isDone() == false) {
				it.set_isDone();
				return true;
			}
			else
				return false;
		}
	return false;
	        

}

void Repository::print_repo()
{
	for (auto it : this->v)
		it.print_project();
}

double Repository::cost_repo()
{
	double price = 0;
	for (auto it : v)
		if(it.get_isDone())
			price += it.get_cost();

	return price;
}
