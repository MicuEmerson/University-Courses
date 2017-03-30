#pragma once
#include "domain.h"
#include "dynamicArr.h"
class Repository {

private:
	DynamicVector <Coat> v;

public:

	/*Function for adding an element
	  INPUT:
	      - Coat x = an object of the class Coat
	  OUTPUT:
	      - True is we successfully added the element into repo, false otherwise(if the element is already in the repo)
	*/
	bool add(Coat x);

	/*Function for finding an element, iterates into whole repo and search the element that we give for input.
	  An element is uniquely determinated by size and color.
	INPUT:
	- Coat x = an object of the class Coat, searched element
	OUTPUT:
	- Returns an integer that is the position of the searched element in repo, if the element don't exist it return -1.
	*/
	int find(Coat x);

	/*Function for deleting, if the element that we wanna to delete is in repo, it will interchange the it the last element
	  and we will delete the last element.
	INPUT:
	- Coat x = an object of the class Coat, that we will delete it
	OUTPUT:
	- Return true if we succesfully deleted it, false if we don't find it in our repo.
	*/
	bool del(Coat x);

	/*Function for updateing an element, the idea here is to delete the elem that we wanna to update and to add a new one.
	  The order is not mandatory so we can apply this "update process"
	INPUT:
	- Coat x = an object of the class Coat, that we wanna to update
	- Coat y = an object of the class Coat, containing the new values for updateing
	OUTPUT:
	- Return true if we succesfully updated it, false if we don't find it in our repo.
	*/
	bool update(Coat x, Coat y);

	/*Function for printing the whole repo.	  
	*/
	void print();

	/*Function that get all the elements from the repo.
	INPUT:
	    - N\A
	OUTPUT:
	- Return an pointer to our first element from our dynamic vector of Coats.
	*/
	Coat* getAll();

	/*Function that return the size of the repo.
	INPUT:
	- N\A
	OUTPUT:
	- Return an integer that is the size of repo.
	*/
	int getSize();

};