#pragma once
#include "domain.h"

typedef struct {

	Offer *vec[100];
	int n;

}OfferRepo;


/*
In this function we create a new strucutre OfferRepo
Input:
      - n\a
Output:
      - n\a
*/
OfferRepo *create_repo();

/*
In this function we clean our repository(vector) and also the root pointer of repository.
Input:
     - n\a
Ouput:
     - OfferRepo *r = the pointer of OfferRepo structure
*/
void free_repo(OfferRepo *r);

/*
In this function we search an offer.
An offer is uniquely identified by his destination and date.
Input:
	- OfferRepo *r = the pointer of OfferRepo structure
	- char *dest = a pointer to a char array (destination)
	- int d1 = day
	- int m1 = mounth
	- int y1 = year
Output:
	- Return index of searched offer if it finds it, else return -1
*/
int find_offer(OfferRepo *r, char *dest, int d1, int m1, int y1);

/*
In this function we update an offer is it exist.
An offer is uniquely identified by his destination and date.
Params:
	- OfferRepo *r = the pointer of OfferRepo structure
	- char *dest1 = a pointer to a char array (destination) to searh the offer that we wanna update
	- int d1 = day to searh the offer that we wanna update
	- int m1 = mounth to searh the offer that we wanna update
	- int y1 = year to searh the offer that we wanna update

	- char *type2 = a pointer to a char array (type) for update
	- char *dest1 = a pointer to a char array (destination) for update
	- int d2 = day for for update
	- int m2 = mounth for update
	- int y2 = year for update
Output:
	- Return 0 if no such an offer in repository, else return 1 if the update operation was made
*/
int update_offer_repo(OfferRepo *r, char *dest1, int d1, int m1, int y1, char *type2, char *dest2, int d2, int m2, int y2, int p2);


/*
  Iterate into our offers array and print them with print_offer function made in domain.h
*/
void print_repo(OfferRepo *r);


/*
In this function we try to add an new offer into our repo if it's not already there
Params:
	- OfferRepo *r = pointer to an OfferRepo structure
	- OfferRepo *x = pointer to an Offer structure
Ouput:
	- return 0 if x is already there, else return 1
*/
int add_offer(OfferRepo *v, Offer *x);

/*
In this function we try to add an new offer into our repo if it's not already there.
An offer is uniquely identified by its destination and departure date.
Params:
	- OfferRepo *r = pointer to an OfferRepo structure
	- OfferRepo *x = pointer to an Offer structure
Ouput:
	- return -1 if x is not in repo, else return 1 if we delete it
*/
int delete_offer(OfferRepo *v, char *dest, int d, int m, int y);

void test_repo();






