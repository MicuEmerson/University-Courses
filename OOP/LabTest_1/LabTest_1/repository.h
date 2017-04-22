#pragma once
#include <vector>
#include "domain.h"
class Repository {

private:
	vector <Project> v;

public:
	/*
	  Function for finding an element;
	  INPUT: Project x;
	  OUTPUT: True if we found it in our repo, else false
	*/
	bool find(Project x);

	/*
	Function for adding an elemtn
	INPUT: Project x;
	OUTPUT: True if we found succesfuly added it, else false
	*/
	bool add(Project x);

	/*
	 Function for mark an element 'isDone' with true;
	 INPUT: Project x;
	 OUTPUT: True if we found it and the element was with isDone = false, else false
	*/
	bool mark(Project x);
	
	//Simply function for printing the repository
	void print_repo();

	//Sort the elements that have isDone = false by date.
	void sort_repo();

	// Returns a double result, that is the cost of all elements in repo that have isDone = true 
    double cost_repo();
	// return the pointer of the repo vector
	vector<Project> getAll() { return this->v; }


};