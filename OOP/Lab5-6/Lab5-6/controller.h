#pragma once
#include "repository.h"
#include "domain.h"
#include "shopBag.h"
#include "dynamicArr.h"

class Controller {

private:
	Repository repo;
	ShopBag bag;
public:

	Controller(const Repository& r) : repo(r) {}
	bool add_repo(Coat x);
	bool del_repo(Coat x);
	bool update_repo(Coat x, Coat y);
	void print_repo();
	void add_bag(Coat x);
	int get_price_bag();
	void print_bag();
	
	Coat* getAll_repo();
	int getSize_repo();

};