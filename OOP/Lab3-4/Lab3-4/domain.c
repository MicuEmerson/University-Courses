#include "domain.h";
#include <string.h>;
#include <stdlib.h>;
#include <stdio.h>

Offer* create_offer(char *type, char *destination, int day, int mounth, int year, int price)
{
	Offer *x = (Offer*)malloc(sizeof(Offer));

	x->type = (char*)malloc(strlen(type) + 1);
	strcpy(x->type, type);

	x->destination = (char*)malloc(strlen(destination) + 1);
	strcpy(x->destination, destination);

	x->day = day;
	x->mounth = mounth;
	x->year = year;
	x->price = price;
	return x;
}


void free_offer(Offer *x) {
	 
	free(x->type);
	free(x->destination);
	free(x);

}
void print_offer(Offer* x){
	
	printf("Type: %s, Destionatin: %s, Departure: %d / %d / %d, Price: %d\n", x->type, x->destination, x->day, x->mounth, x->year, x->price);

}

Offer *copy_offer(Offer *x) {

	return create_offer(x->type, x->destination, x->day, x->mounth, x->year, x->price);

}
