#pragma once
#include "domain.h"

typedef struct {

	Offer **vec;
	int n;
	int capacity;

}DynamicArr;

/*
   In this function we create a new object 'dynamicArr' with capacity as a given value
   Return a pointer to an DynamicArr structure
*/
DynamicArr *create_dynamicArr(int capacity);

/*
   In this function we free all the elements allocated in a dynamicArr structure
*/
void free_dynamicArr(DynamicArr *myArr);
/*
   In this function we reallocate the vec size, double his capacity
*/
void realloc_dynamicArr(DynamicArr *myArr);
/*
	In this function we add at the end a new Offer element into 'vec' array;
*/
void add_dynamicArr(DynamicArr *myArr, Offer *x);
/*
	In this function we there an  element from our 'vec' at position 'pos'
*/
void delete_dynamicArr(DynamicArr *myArr, int pos);

void test_dynamicArr();