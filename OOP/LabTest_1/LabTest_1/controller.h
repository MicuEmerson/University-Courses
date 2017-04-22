#pragma once
#include "repository.h"
#include "domain.h"
#include <algorithm>
using namespace std;

class Controller {

private:

	Repository repo;

public:
	
	Controller(Repository r) : repo(r) {}
	//Check repo for specification
	bool add_ctrl(Project x) { return this->repo.add(x); }
	//Check repo for specification
	bool mark_ctrl(Project x) { return this->repo.mark(x); }
	//Check repo for specification
	double cost_ctrl() { return this->repo.cost_repo(); }
	//Check repo for specification
	void print_ctrl() { this->repo.print_repo(); }

	bool cmp(Project x, Project y);
	void sort1();

};

