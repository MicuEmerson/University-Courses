#include "dynamic_array2.h"


DynamicArr2 *create_dynamicArr2(int capacity) {

	DynamicArr2 *myArr = (DynamicArr2*)malloc(sizeof(DynamicArr2));
	myArr->vec = (OfferRepo*)malloc(capacity * sizeof(OfferRepo));
	myArr->n = 0;
	myArr->index = -1;
	myArr->capacity = capacity;
	return myArr;
}



void free_dynamicArr2(DynamicArr2 *myArr) {

	int i;
	for (i = 0; i < myArr->n; i++)
		free_repo(myArr->vec[i]);

	free(myArr->vec);
	free(myArr);
}

void realloc_dynamicArr2(DynamicArr2 *myArr) {

	myArr->capacity = myArr->capacity * 2;
	myArr->vec = (OfferRepo*)realloc(myArr->vec, myArr->capacity * sizeof(OfferRepo));
}

void add_dynamicArr2(DynamicArr2 *myArr, OfferRepo *x) {

	if (myArr->n == myArr->capacity)
		realloc_dynamicArr(myArr);

	myArr->vec[myArr->n] = x;
	myArr->n++;
	myArr->index++;
}


void delete_dynamicArr2(DynamicArr2 *myArr, int pos)
{
	int i;
	for (i = pos; i < myArr->n - 1; i++)
		myArr->vec[i] = myArr->vec[i + 1];

	myArr->n--;
}

