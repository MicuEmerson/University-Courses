#pragma once
#include "repository.h"
typedef struct {

	OfferRepo **vec;
	int n;
	int capacity;
	int index;

}DynamicArr2;

/*
	Creates a new object DynamicArr2
*/
DynamicArr2 *create_dynamicArr2(int capacity);

/*
	Delete an DynamicArr2 object
*/
void free_dynamicArr2(DynamicArr2 *myArr);

/*
	Double the current size of the vector using realloc
*/
void realloc_dynamicArr2(DynamicArr2 *myArr);

/*
	Add into array a new element
*/
void add_dynamicArr2(DynamicArr2 *myArr, OfferRepo *x);

/*
 We simply check if the index is not less then -1, to be able to perform an undo operation
*/
int check_undo(DynamicArr2 *myArr);

/*
We simply check if the index is not equal with n(length), to be able to perform an redo operation
*/
int check_redo(DynamicArr2 *myArr);

/*
 This function is made for redo, when we do a new operation. When we perform a new operation redo will be unabled,
 We itarete from the n until the index and delete all the elements
*/
void delete_dynamicArr2(DynamicArr2 *myArr);