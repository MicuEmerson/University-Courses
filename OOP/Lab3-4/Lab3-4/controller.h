#pragma once
#include "repository.h"
#include "dynamic_array2.h"
#include "operationStack.h"
#include "domain.h"

typedef struct {

	OfferRepo *r;
	DynamicArr2 *myList;
	OperationsStack *undoStack;
	OperationsStack *redoStack;
	int OK;

}Controller;

Controller *create_ctrl(OfferRepo *r);
void free_ctrl(Controller *ctrl);
void test_controller();

/*
   We try to add an new element, if it passes the verification we save our current repo into myList(list of repositories) and we add the new element
   into current repo.
   Input: 
        - Controller * ctrl = controller pointer
		- Offer *x =  new object for add
   Ouput:
        - Return true if we added the new element, false otherwise
*/
int add_offer_ctrl(Controller* ctrl, Offer *x);

/*
We try to delete an element, if it passes the verification we save our current repo into myList(list of repositories) and we delete the element
from our repo.
Input:
- Controller * ctrl = controller pointer
- Others are simply parameters ( check repository.h for more details )
Ouput:
- Return true if we deleted, false otherwise
*/
int delete_offer_ctrl(Controller *ctrl, char *dest, int d, int m, int y);

/*
We try to update an element, if it passes the verification we save our current repo into myList(list of repositories) and we update  the element
from our repo.
Input:
- Controller * ctrl = controller pointer
- Others are simply parameters ( check repository.h for more details )
Ouput:
- Return true if we updated, false otherwise
*/
int update_offer_ctrl(Controller *ctrl, char *dest1, int d1, int m1, int y1, char *type2, char *dest2, int d2, int m2, int y2, int p2);
void print_ctrl(Controller *ctrl);

/*
	Filter function.
	In this function we return an OfferRepo* pointer after we put in our new repo filtred elements
	Input: 
	    - Controller* Ctrl = controller pointer
		- Offer *x = object where we stored the elements that we need in compare, the object don't have to have filled all the fields
		- int(*cmp)(Offer*, Offer*) =  function pointer for compare
	Output:
	    - a pointer to our new repo where we stored the filtred elements
*/
OfferRepo* filter(Controller *ctrl, Offer *x, int(*cmp)(Offer*, Offer*));

/*
	Sort function.
	In this function we sort our repo.
	Input:
		- Controller* Ctrl = controller pointer
		- int(*cmp)(Offer*, Offer*) =  function pointer for compare
	Output:
	    - n\a

*/
void sort(Controller* Ctrl, int(*cmp)(Offer*, Offer*));


/*
   In the fuctions undo and redo we check if it is able to perform this operations, if it is we free our repo pointer and we take
   a new repo from the undoRedoList(myList) which is a list of repositories.
   Input:
		- Controller* Ctrl = controller pointer
   Output:
        - True is we perform the operations
		- False otherwise
*/
int undo(Controller* ctrl);
int redo(Controller* ctrl);

int undo_stack(Controller *ctrl);
int redo_stack(Controller *ctrl);


/*
     Below we have compare functions.
	 For input it take two pointer to Offer objects and compare them.
	 Return TRUE if it passed the filter, else FASLE.
   
*/
int cmp_date(Offer *x, Offer *y);
int cmp_dest(Offer *x, Offer *y);
int cmp_price(Offer *x, Offer *y);
int cmp_price2(Offer *x, Offer *y);
int cmp_sortType(Offer *x, Offer *y);
int cmp_sortDestination(Offer *x, Offer *y);
int cmp_sortDate(Offer *x, Offer *y);
int cmp_sortPrice(Offer *x, Offer *y);