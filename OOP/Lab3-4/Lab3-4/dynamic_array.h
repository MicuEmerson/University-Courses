#pragma once
#include "domain.h"

typedef struct {

	Offer **vec;
	int n;
	int capacity;

}DynamicArr;

DynamicArr *create_dynamicArr(int capacity);
void free_dynamicArr(DynamicArr *myArr);
void realloc_dynamicArr(DynamicArr *myArr);
void add_dynamicArr(DynamicArr *myArr, Offer *x);
void delete_dynamicArr(DynamicArr *myArr, int pos);