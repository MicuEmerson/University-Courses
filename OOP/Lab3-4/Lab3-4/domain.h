#pragma once

typedef struct {

	char *type;
	char *destination;
	int day;
	int mounth;
	int year;
	int price;

}Offer;

Offer *create_offer(char *type, char *destination, int day, int mounth, int year, int price);
void free_offer(Offer *x);
void print_offer(Offer *x);
