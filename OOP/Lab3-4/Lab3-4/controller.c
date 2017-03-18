#include "controller.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


Controller *create_ctrl(OfferRepo *r) {

	Controller *ctrl = (Controller *)malloc(sizeof(Controller));
	ctrl->r = r;
	ctrl->myList = create_dynamicArr2(1);
	return ctrl;
}

void free_ctrl(Controller *ctrl) {
	
	free_repo(ctrl->r);
	free_dynamicArr2(ctrl->myList);
	free(ctrl);
}

int undo(Controller* ctrl) {
	if (check_undo(ctrl->myList)) {

		OfferRepo *r2 = ctrl->r;
		ctrl->r = copy_repo(ctrl->myList->vec[--ctrl->myList->index]);
		free_repo(r2);
		return 1;
	}
	return 0;
}

int redo(Controller *ctrl) {
	if (check_redo(ctrl->myList)) {

		OfferRepo *r2 = ctrl->r;
		ctrl->r = copy_repo(ctrl->myList->vec[++ctrl->myList->index]);
		free_repo(r2);
		return 1;
	}
	return 0;
}


int add_offer_ctrl(Controller *ctrl, Offer *x) {

	int status = add_offer(ctrl->r, x);
	OfferRepo *y = copy_repo(ctrl->r);

	if (status == 1) {
		delete_dynamicArr2(ctrl->myList);
		add_dynamicArr2(ctrl->myList, y);
	}
	else
		free_repo(y);
		
	return status;
}

int update_offer_ctrl(Controller *ctrl, char *dest1, int d1, int m1, int y1, char *type2, char *dest2, int d2, int m2, int y2, int p2) {

	int status = update_offer(ctrl->r, dest1, d1, m1, y1, type2, dest2, d2, m2, y2, p2);
	OfferRepo *x = copy_repo(ctrl->r);

	if (status == 1) {
		delete_dynamicArr2(ctrl->myList);
		add_dynamicArr2(ctrl->myList, x);
	}
	else
		free_repo(x);

	return status;
}

int delete_offer_ctrl(Controller *ctrl, char *dest, int d, int m, int y) {
	
	int status = delete_offer(ctrl->r, dest, d, m, y);
	OfferRepo *x = copy_repo(ctrl->r);

	if (status == 1) {
		delete_dynamicArr2(ctrl->myList);
		add_dynamicArr2(ctrl->myList, x);
	}
	else
		free_repo(x);

	return status;
}

void print_ctrl(Controller *ctrl) {

	print_repo(ctrl->r);
}

void swap(Offer **a, Offer **b) {
	
	Offer *aux = *a;
	*a = *b;
	*b = aux;
}


int cmp_dest(Offer *x, Offer *y) {

	return  strstr(x->destination, y->destination) || y->destination == NULL;
}


int cmp_date(Offer *x, Offer *y) {

	if (strcmp(x->type, y->type) == 0)
		if (x->year >= y->year)
			if (x->mounth >= y->mounth)
				if (x->day >= y->day)
					return 1;
	return 0;
}

int cmp_price(Offer *x, Offer *y) {

	if (strcmp(x->type, y->type) == 0)
		if (x->price < y->price)
			return 1;
	return 0;

}
int cmp_price2(Offer *x, Offer *y) {

	return x->price <= y->price;

}

OfferRepo* filter(Controller *ctrl, Offer *x, int(*cmp)(Offer*, Offer*)) {

	int i, j;
	OfferRepo *repo = create_repo();

	for (i = 0; i < ctrl->r->arr->n; i++) 
		if (cmp(ctrl->r->arr->vec[i], x)) {
			
			Offer *y = create_offer(ctrl->r->arr->vec[i]->type, ctrl->r->arr->vec[i]->destination, ctrl->r->arr->vec[i]->day, ctrl->r->arr->vec[i]->mounth, ctrl->r->arr->vec[i]->year, ctrl->r->arr->vec[i]->price);
			add_offer(repo, y);
		}

	for (i = 0; i < repo->arr->n; i++)
		for (j = i; j < repo->arr->n; j++)
			if (repo->arr->vec[i]->price > repo->arr->vec[j]->price)
				swap(&repo->arr->vec[i], &repo->arr->vec[j]);
					
	return repo;
}

int cmp_sortType(Offer *x, Offer *y) {

	return strcmp(x->type, y->type) < 1;
	
}

int cmp_sortDestination(Offer *x, Offer *y) {

	return strcmp(x->destination, y->destination) < 1;

}

int cmp_sortDate(Offer *x, Offer *y) {

	if (x->year <= y->year)
		if (x->mounth <= y->mounth)
			if (x->day <= y->day)
				return 1;
	return 0;
}

int cmp_sortPrice(Offer *x, Offer *y) {

	if (x->price <= y->price)
				return 1;
	return 0;
}


void sort(Controller *ctrl, int(*cmp)(Offer*, Offer*)) {

	int i, j;
	for (i = 0; i < ctrl->r->arr->n; i++)
		for (j = i; j < ctrl->r->arr->n; j++)
			if (cmp(ctrl->r->arr->vec[i], ctrl->r->arr->vec[j])) 
				swap(&ctrl->r->arr->vec[i], &ctrl->r->arr->vec[j]);
}



void init_for_test(Controller *ctrl) {

	Offer *a = create_offer("Seaside", "Maldive", 11, 12, 2017, 825);
	Offer *b = create_offer("Mountain", "Cavnic", 12, 11, 2017, 350);
	Offer *c = create_offer("CityBreak", "London", 13, 10, 2017, 200);
	Offer *d = create_offer("Mountain", "Retezat", 14, 9, 2015, 250);
	
	add_offer_ctrl(ctrl, a);
	add_offer_ctrl(ctrl, b);
	add_offer_ctrl(ctrl, c);
	add_offer_ctrl(ctrl, d);
}


void test_filter_date() {

	OfferRepo *r = create_repo();
	Controller *ctrl = create_ctrl(r);
	Offer *x;
	init_for_test(ctrl);

	x = create_offer("Mountain","", 1, 1, 1, 0);
	OfferRepo *repo = filter(ctrl, x, cmp_date);
	assert(repo->arr->n == 2);
	free_offer(x);
	free_repo(repo);

	x = create_offer("Mountain", "", 1, 10, 2020, 0);
	OfferRepo *repo1 = filter(ctrl, x, cmp_date);
	assert(repo1->arr->n == 0);
	free_offer(x);
	free_repo(repo1);
	
	x = create_offer("Seaside", "", 1, 1, 2017, 0);
	OfferRepo *repo2 = filter(ctrl, x, cmp_date);
	assert(repo2->arr->n == 1);
	free_offer(x);
	free_repo(repo2);
	
	x = create_offer("Mountain", "", 1, 10, 2016, 0);
	OfferRepo *repo3 = filter(ctrl, x, cmp_date);
	assert(repo3->arr->n == 1);
	free_offer(x);
	free_repo(repo3);
	

	free_ctrl(ctrl);
}

void test_filter_destination() {

	OfferRepo *r = create_repo();
	Controller *ctrl = create_ctrl(r);
	Offer *x;
	init_for_test(ctrl);

	x = create_offer("", "e", 0, 0, 0, 0);
	OfferRepo *repo = filter(ctrl, x, cmp_dest);
	assert(repo->arr->n == 2);
	free_offer(x);
	free_repo(repo);
	 
	x = create_offer("", "", 0, 0, 0, 0);
	OfferRepo *repo1 = filter(ctrl, x, cmp_dest);
	assert(repo1->arr->n == 4);
	free_offer(x);
	free_repo(repo1);

	x = create_offer("", "qqq", 0, 0, 0, 0);
	OfferRepo *repo2 = filter(ctrl, x, cmp_dest);
	assert(repo2->arr->n == 0);
	free_offer(x);
	free_repo(repo2);
	
	free_ctrl(ctrl);
}

void test_sort() {
    
	OfferRepo *r = create_repo();
	Controller *ctrl = create_ctrl(r);
	init_for_test(ctrl);

	sort(ctrl, cmp_sortPrice);
	assert(ctrl->r->arr->vec[0]->price == 825);
	assert(ctrl->r->arr->vec[3]->price == 200);

	sort(ctrl, cmp_sortDestination);
	assert(strcmp(ctrl->r->arr->vec[0]->destination, "Retezat") == 0);
	assert(strcmp(ctrl->r->arr->vec[3]->destination, "Cavnic") == 0);
	
	sort(ctrl, cmp_sortType);
	assert(strcmp(ctrl->r->arr->vec[0]->type, "Seaside") == 0);
	assert(strcmp(ctrl->r->arr->vec[3]->type, "CityBreak") == 0);

	free_ctrl(ctrl);
}

void test_controller() {

	test_filter_date();
	test_filter_destination();
	test_sort();
}
