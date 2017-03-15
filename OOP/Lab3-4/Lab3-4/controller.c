#include "controller.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


Controller *create_ctrl(OfferRepo *r) {

	Controller *ctrl = (Controller *)malloc(sizeof(Controller));
	ctrl->r = r;
	return ctrl;
}

void free_ctrl(Controller *ctrl) {
	free_repo(ctrl->r);
	free(ctrl);
}

int add_offer_ctrl(Controller *ctrl, Offer *x) {

	return add_offer(ctrl->r, x);
}

int update_offer_ctrl(Controller *ctrl, char *dest1, int d1, int m1, int y1, char *type2, char *dest2, int d2, int m2, int y2, int p2) {

	return update_offer_repo(ctrl->r, dest1, d1, m1, y1, type2, dest2, d2, m2, y2, p2);
}

int delete_offer_ctrl(Controller *ctrl, char *dest, int d, int m, int y) {

	return delete_offer(ctrl->r, dest, d, m, y);
}

void print_ctrl(Controller *ctrl) {

	print_repo(ctrl->r);
}

void swap(Offer **a, Offer **b) {
	
	Offer *aux = *a;
	*a = *b;
	*b = aux;
}

OfferRepo* filter_destination(Controller *ctrl, char *destination) {

	int i, j;
	OfferRepo *repo = create_repo();

	for (i = 0; i < ctrl->r->arr->n; i++) {
		
		if (strstr(ctrl->r->arr->vec[i]->destination, destination) || destination == NULL) {
			Offer *y = create_offer(ctrl->r->arr->vec[i]->type, ctrl->r->arr->vec[i]->destination, ctrl->r->arr->vec[i]->day, ctrl->r->arr->vec[i]->mounth, ctrl->r->arr->vec[i]->year, ctrl->r->arr->vec[i]->price);
			add_offer(repo, y);
		}
	}
 
	for (i = 0; i < repo->arr->n; i++)
		for (j = i; j < repo->arr->n; j++)
			if (repo->arr->vec[i]->price > repo->arr->vec[j]->price)
				swap(&repo->arr->vec[i], &repo->arr->vec[j]);
						
	return repo;
}

OfferRepo* filter_date(Controller *ctrl, char *type, int day, int mounth, int year) {

	OfferRepo *repo = create_repo();
	int i;
	for (i = 0; i < ctrl->r->arr->n; i++)
		if (strcmp(ctrl->r->arr->vec[i]->type, type) == 0)
			if (ctrl->r->arr->vec[i]->year >= year)
				if (ctrl->r->arr->vec[i]->mounth >= mounth)
					if (ctrl->r->arr->vec[i]->day >= day) {
						Offer *y = create_offer(ctrl->r->arr->vec[i]->type, ctrl->r->arr->vec[i]->destination, ctrl->r->arr->vec[i]->day, ctrl->r->arr->vec[i]->mounth, ctrl->r->arr->vec[i]->year, ctrl->r->arr->vec[i]->price);
						add_offer(repo, y);
					}
	return repo;
}

void filter_price(Controller *ctrl, char *type, int price) {

	OfferRepo *repo = create_repo();
	int i, j;
	for (i = 0; i < ctrl->r->arr->n; i++) {
		if (strcmp(ctrl->r->arr->vec[i]->type, type) == 0)
			if (ctrl->r->arr->vec[i]->price < price) {
				Offer *y = create_offer(ctrl->r->arr->vec[i]->type, ctrl->r->arr->vec[i]->destination, ctrl->r->arr->vec[i]->day, ctrl->r->arr->vec[i]->mounth, ctrl->r->arr->vec[i]->year, ctrl->r->arr->vec[i]->price);
				add_offer(repo, y);
			}
	}

	for (i = 0; i < repo->arr->n; i++)
		for (j = i; j < repo->arr->n; j++)
			if (repo->arr->vec[i]->price > repo->arr->vec[j]->price)
				swap(&repo->arr->vec[i], &repo->arr->vec[j]);

	print_repo(repo);
	free_repo(repo);

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
	init_for_test(ctrl);
	
	
	OfferRepo *repo = filter_date(ctrl, "Mountain", 1, 1, 1);
	assert(repo->arr->n == 2);
	free_repo(repo);

	OfferRepo *repo1 = filter_date(ctrl, "Mountain", 1, 10, 2020);
	assert(repo->arr->n == 0);
	free_repo(repo1);
	
	OfferRepo *repo2 = filter_date(ctrl, "Seaside", 1, 10, 2000);
	assert(repo->arr->n == 1);
	free_repo(repo2);

	OfferRepo *repo3 = filter_date(ctrl, "Mountain", 1, 10, 2016);
	assert(repo->arr->n == 1);
	free_repo(repo3);

	free_ctrl(ctrl);
		
}

void test_filter_destination() {

	OfferRepo *r = create_repo();
	Controller *ctrl = create_ctrl(r);
	init_for_test(ctrl);

	OfferRepo *repo = filter_destination(ctrl, "e");
	assert(repo->arr->n == 2);
	free_repo(repo);

	OfferRepo *repo1 = filter_destination(ctrl, "");
	assert(repo->arr->n == 4);
	free_repo(repo1);

	OfferRepo *repo2 = filter_destination(ctrl, "qqq");
	assert(repo->arr->n == 0);
	free_repo(repo2);

	free_ctrl(ctrl);
}

void test_controller() {

	test_filter_date();
	test_filter_destination();
}
