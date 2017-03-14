#include "dynamic_array.h"


DynamicArr *create_dynamicArr(int capacity) {

	DynamicArr *myArr = (DynamicArr*)malloc(sizeof(DynamicArr));
	myArr->elems = (Offer*)malloc(capacity * sizeof(Offer));
	myArr->len = 0;
	myArr->capacity = capacity;
	return myArr;
}

void free_dynamicArr(DynamicArr *myArr) {

	free(myArr->elems);
	free(myArr);
}

void realloc_dynamicArr(DynamicArr *myArr) {

	myArr->capacity = myArr->capacity * 2;
	myArr->elems = (Offer*)realloc(myArr->elems, myArr->capacity * sizeof(Offer));
}

void add_dynamicArr(DynamicArr *myArr, Offer *x) {

	if (myArr->len == myArr->capacity)
		realloc_dynamicArr(myArr);

	myArr->elems[myArr->len] = x;
	myArr->len++;
}


void delete_dynamicArr(DynamicArr *myArr, int pos)
{
	int i;
	for (i = pos; i < myArr->len - 1; i++)
		myArr->elems[i] = myArr->elems[i + 1];

	myArr->len--;
}

