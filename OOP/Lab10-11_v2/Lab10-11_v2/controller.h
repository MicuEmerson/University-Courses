#pragma once
#include "repository.h"
#include "domain.h"
#include "shopBag.h"
#include "coatValidator.h"


class Controller {

private:
	Repository repo;
	ShopBag *bag;
	CoatValidator ct;
public:

	Controller(const Repository& r, ShopBag *b, CoatValidator x) : repo(r), bag(b), ct(x) {}
	
	void add_repo(Coat x) {
		
		ct.validate(x);
		this->repo.add(x);
	
	}
	bool del_repo(Coat x) { return this->repo.del(x); }
	bool update_repo(Coat x, Coat y) { return this->repo.update(x, y); }
	void print_repo() { this->repo.print(); }

	 void add_bag(Coat x) { this->bag->add(x); }
	 int get_price_bag() { return  this->bag->get_bagPrice(); }
     void print_bag() { this->bag->print(); }
	
	std::vector<Coat>& getAll_repo() { return this->repo.getAll(); }

	void writeToFile_repo() { this->repo.writeToFile(); }
	void readFromFile_repo() { this->repo.readFromFile(); }
	void openThings_ctrl() { this->bag->openThings(); }
};