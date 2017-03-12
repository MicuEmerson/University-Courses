#pragma once
#include "repository.h"

typedef struct {

	OfferRepo *r;

}Controller;

Controller *create_ctrl(OfferRepo *r);
void free_ctrl(Controller *ctrl);

int add_offer_ctrl(Controller* ctrl, Offer *x);
int delete_offer_ctrl(Controller *ctrl, char *dest, int d, int m, int y);
int update_offer_ctrl(Controller *ctrl, char *dest1, int d1, int m1, int y1, char *type2, char *dest2, int d2, int m2, int y2, int p2);
void print_ctrl(Controller *ctrl);
void test_controller();

/*
   In this function we filter the repo. The condition for passing the filter is to be a substring
   of a given destination. We will insert the good offer into a new repository, after that we will
   sort that repository and print it, then we destroy it.
   Input:
		- Controller *ctrl = pointer to a Controller structure
		- char *destination = given destination
   Ouput:
        - Return a pointer to an new repository where our offer are filtred

*/
OfferRepo* filter_destination(Controller *ctrl, char *destination);


/*
  In this function we filter the repo. The condition for passing the filter is to have the same type like an given type, and the date
  to be at >= then a given date.
  Input:
		- Controller *ctrl = pointer to a Controller structure
		- char *type = given type 
		- int date, mounth, year = date
  Output:
        - Return a pointer to an new repository where our offer are filtred
        
*/
OfferRepo* filter_date(Controller *ctrl, char *type, int day, int mounth, int year);