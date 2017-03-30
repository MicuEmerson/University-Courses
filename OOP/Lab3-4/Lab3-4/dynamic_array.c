#include "dynamic_array.h"
#include <assert.h>

DynamicArr *create_dynamicArr(int capacity) {

	DynamicArr *myArr = (DynamicArr*)malloc(sizeof(DynamicArr));
	myArr->vec = (Offer*)malloc(capacity * sizeof(Offer));
	myArr->n = 0;
	myArr->capacity = capacity;
	return myArr;
}

void free_dynamicArr(DynamicArr *myArr) {

	int i;
	for (i = 0; i < myArr->n; i++) {
		free_offer(myArr->vec[i]);
	}
	free(myArr->vec);
	free(myArr);
}


void realloc_dynamicArr(DynamicArr *myArr) {

	myArr->capacity = myArr->capacity * 2;
	myArr->vec = (Offer*)realloc(myArr->vec, myArr->capacity * sizeof(Offer));
}

void add_dynamicArr(DynamicArr *myArr, Offer *x) {

	if (myArr->n  == myArr->capacity)
		realloc_dynamicArr(myArr);

	myArr->vec[myArr->n] = x;
	myArr->n++;
}


void delete_dynamicArr(DynamicArr *myArr, int pos)
{
	
	int n = myArr->n - 1;
	

	myArr->vec[pos]->day = myArr->vec[n]->day;
	myArr->vec[pos]->mounth = myArr->vec[n]->mounth;
	myArr->vec[pos]->year = myArr->vec[n]->year;
	myArr->vec[pos]->price = myArr->vec[n]->price;
	
	free(myArr->vec[pos]->destination);
	free(myArr->vec[pos]->type);
	myArr->vec[pos]->type = (char*)malloc(strlen(myArr->vec[n]->type) + 1);
	myArr->vec[pos]->destination = (char*)malloc(strlen(myArr->vec[n]->destination) + 1);
	strcpy(myArr->vec[pos]->type, myArr->vec[n]->type);
	strcpy(myArr->vec[pos]->destination, myArr->vec[n]->destination);
	


    free_offer(myArr->vec[n]);
	myArr->n--;
	
}

void test_dynamicArr() {

	DynamicArr *myArr = create_dynamicArr(1);
	assert(myArr->capacity == 1);
	
	Offer *a = create_offer("Seaside", "Maldive", 11, 12, 2017, 825);
	

	Offer *b = create_offer("Mountain", "Cavnic", 12, 11, 2017, 350);
	Offer *c = create_offer("CityBreak", "London", 13, 10, 2017, 200);
	add_dynamicArr(myArr, a);
	add_dynamicArr(myArr, b);
	add_dynamicArr(myArr, c);
	assert(myArr->capacity == 4);
	delete_dynamicArr(myArr, 0);
	assert(myArr->capacity == 4);
	assert(myArr->n == 2);
	
	
	free_dynamicArr(myArr);
}

