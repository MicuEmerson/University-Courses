#include "repository.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
OfferRepo *create_repo() {

	OfferRepo *r = (OfferRepo*)malloc(sizeof(OfferRepo));
    r->arr = create_dynamicArr(1);
	return r;
}

void free_repo(OfferRepo *r) {
	
	free_dynamicArr(r->arr);
	free(r);
}

int add_offer(OfferRepo *r, Offer *x) {

	if (find_offer(r, x->destination, x->day, x->mounth, x->year) != -1)
		return 0;

	add_dynamicArr(r->arr, x);
	return 1;
}


int find_offer(OfferRepo *r, char *dest, int d1, int m1, int y1) {
	
	int i;
	
	for (i = 0; i < r->arr->n; i++)
		if (strcmp(r->arr->vec[i]->destination, dest) == 0)
			if (r->arr->vec[i]->day == d1)
				if (r->arr->vec[i]->mounth == m1)
					if (r->arr->vec[i]->year == y1)
						return i;
	return -1;
}

int update_offer(OfferRepo *r, char *dest1, int d1, int m1, int y1, char *type2, char *dest2, int d2, int m2, int y2, int p2) {
	
	int idx = find_offer(r, dest1, d1, m1, y1);
	if (idx == -1)
		return 0;
	
	delete_offer(r, dest1, d1, m1, y1);
	Offer *x = create_offer(type2, dest2, d2, m2, y2, p2);
	int status = add_offer(r, x);

	if (status == 0) {
		free(x);
		return 0;
	}
	else
		return 1;

}


int delete_offer(OfferRepo *r, char *dest, int d, int m, int y) {
	
	int poz = find_offer(r, dest, d, m, y);
	if (poz == -1)
		return 0;
	
	delete_dynamicArr(r->arr, poz);
	return 1;
}

void print_repo(OfferRepo *r) {

	int i;
	for (i = 0; i < r->arr->n; i++)
		print_offer(r->arr->vec[i]);
}

OfferRepo *copy_repo(OfferRepo *r) {

	int i;
	OfferRepo *r2 = create_repo();
	for (i = 0; i < r->arr->n; i++) {
		Offer *x = create_offer(r->arr->vec[i]->type, r->arr->vec[i]->destination, r->arr->vec[i]->day, r->arr->vec[i]->mounth, r->arr->vec[i]->year, r->arr->vec[i]->price);
		add_offer(r2, x);
	}
	return r2;
}


void test_repo() {

	int idx;
	OfferRepo *r = create_repo();
	Offer *a = create_offer("Seaside", "Maldive", 11, 12, 2017, 825);
	Offer *b = create_offer("Mountain", "Cavnic", 12, 11, 2017, 350);
	Offer *c = create_offer("CityBreak", "London", 13, 10, 2017, 200);
	Offer *d = create_offer("Mountain", "Retezat", 14, 9, 2017, 250);

	add_offer(r, a);
	assert(r->arr->n == 1);
	add_offer(r, b);
	assert(r->arr->n == 2);
	add_offer(r, c);
	assert(r->arr->n == 3);

	add_offer(r, c);
	assert(r->arr->n == 3);
	add_offer(r, d);
	assert(r->arr->n == 4);
	
	idx = find_offer(r, "Maldive", 11, 12, 2017, 825);
	assert(idx == 0);
	idx = find_offer(r, "Retezat", 14, 9, 2017, 250);
	assert(idx == 3);
	
	update_offer(r, "Retezat", 14, 9, 2017, "Mountain", "Clujasdasdsadas", 1, 1, 1, 1);
	assert(strcmp(r->arr->vec[3]->destination, "Clujasdasdsadas") == 0);
	assert(r->arr->vec[3]->price == 1);
	assert(r->arr->vec[3]->day == 1);
	assert(r->arr->vec[3]->mounth == 1);
	assert(r->arr->vec[3]->year == 1);
	
	delete_offer(r, "Maldive", 11, 12, 2017);
	assert(r->arr->n == 3);
	delete_offer(r, "Maldive", 11, 12, 2017);
	assert(r->arr->n == 3);
	delete_offer(r, "Clujasdasdsadas", 1, 1, 1, 1);
	assert(r->arr->n == 2);
	
	free_repo(r);
}
