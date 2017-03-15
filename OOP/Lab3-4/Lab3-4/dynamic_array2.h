#pragma once
#include "repository.h"
typedef struct {

	OfferRepo **vec;
	int n;
	int capacity;
	int index;

}DynamicArr2;

DynamicArr2 *create_dynamicArr2(int capacity);
void free_dynamicArr2(DynamicArr2 *myArr);
void realloc_dynamicArr2(DynamicArr2 *myArr);
void add_dynamicArr2(DynamicArr2 *myArr, OfferRepo *x);
void delete_dynamicArr2(DynamicArr2 *myArr, int pos);