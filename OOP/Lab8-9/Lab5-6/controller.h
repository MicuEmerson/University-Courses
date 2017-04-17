#pragma once
#include "repository.h"
#include "domain.h"
#include "shopBag.h"


class Controller {

private:
	Repository repo;
	ShopBag bag;
public:

	Controller(const Repository& r) : repo(r) {}
	
	bool add_repo(Coat x) { return this->repo.add(x); }
	bool del_repo(Coat x) { return this->repo.del(x); }
	bool update_repo(Coat x, Coat y) { return this->repo.update(x, y); }
	void print_repo() { this->repo.print(); }

	void add_bag(Coat x) { this->bag.add(x); }
	int get_price_bag() { return  this->bag.get_bagPrice(); }
	void print_bag() { this->bag.print(); }
	
	std::vector<Coat> getAll_repo() { return this->getAll_repo(); }
	

};