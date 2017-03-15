#include "dynamic_array.h"


DynamicArr *create_dynamicArr(int capacity) {

	DynamicArr *myArr = (DynamicArr*)malloc(sizeof(DynamicArr));
	myArr->vec = (Offer*)malloc(capacity * sizeof(Offer));
	myArr->n = 0;
	myArr->capacity = capacity;
	return myArr;
}

void free_dynamicArr(DynamicArr *myArr) {

	int i;
	for (i = 0; i < myArr->n; i++)
		free_offer(myArr->vec[i]);
	free(myArr->vec);
	free(myArr);
}

void realloc_dynamicArr(DynamicArr *myArr) {

	myArr->capacity = myArr->capacity * 2;
	myArr->vec = (Offer*)realloc(myArr->vec, myArr->capacity * sizeof(Offer));
}

void add_dynamicArr(DynamicArr *myArr, Offer *x) {

	if (myArr->n == myArr->capacity)
		realloc_dynamicArr(myArr);

	myArr->vec[myArr->n] = x;
	myArr->n++;
}


void delete_dynamicArr(DynamicArr *myArr, int pos)
{
	int i;
	for (i = pos; i < myArr->n - 1; i++)
		myArr->vec[i] = myArr->vec[i + 1];

	myArr->n--;
}

