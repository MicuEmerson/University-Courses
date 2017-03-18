#include "ui.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

UI *create_ui(Controller *ctrl) {

	UI *ui = (UI *)malloc(sizeof(UI));
	ui->ctrl = ctrl;
	return ui;
}

void delete_ui(UI* ui) {

	free_ctrl(ui->ctrl);
	free(ui);
}

void menu() {

	printf("1) Add Offer\n");
	printf("2) Update Offer\n");
	printf("3) Delete Offer\n");
	printf("4) List Offers\n");
	printf("5) Display All The Tourism Offer Contain A Given String \n");
	printf("6) Display All Offers Of A Given Type, Starting From A Given Date\n");
	printf("7) Display All Offers Having A Given Type And A Price Less Than A Given Value, Sorted Ascending By Price\n");
	printf("8) Display All Offers With Price Smaller Then A Given Value\n");
	printf("9) Sort\n");
	printf("10) Undo\n");
	printf("11) Redo\n");
	printf("0) Exit\n\n");
}

int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

void readOffer(char *type, char *dest, int *d, int *m, int *y, int *p) {
	
	printf("Read Offer\n");
	printf("Type: ");
	scanf("%s", type);

	while (strcmp("Mountain", type) && strcmp("CityBreak", type) && strcmp("Seaside", type)) {
		printf("Invalid input, try again!\n");
		printf("Type: ");
		scanf("%s", type);
	}
	
	printf("Destination: ");
	scanf("%s", dest);

	*d = readIntegerNumber("Day: ");
	*m = readIntegerNumber("Mounth: ");
	*y = readIntegerNumber("Year: ");
	*p = readIntegerNumber("Price: ");
}

void readUpdate(char *dest, int *d, int *m, int *y) {

	printf("Destination or Type: ");
	scanf("%s", dest);
	printf("Day: ");
	scanf("%d", d);
	printf("Mounth: ");
	scanf("%d", m);
	printf("Year: ");
	scanf("%d", y);
}


void print_filter(UI *ui, Offer *x, int(*cmp)(Offer*, Offer*)) {

	OfferRepo *repo = filter(ui->ctrl, x, cmp);
	if (repo->arr->n == 0) 
		printf("No such an offer in repository\n");
	else 
		print_repo(repo);

	free_repo(repo);
}



void start_ui(UI* ui) {

	printf("\t TOURISM AGENCY  \n\n");
	int d, m, y, p, cmd, d2, m2, y2;
	char type[100], dest[100], dest2[100], s[100];

	while (1) {
		
		menu();
		cmd = readIntegerNumber("cmd: ");

		if (cmd == 1) {

			readOffer(&type, &dest, &d, &m, &y, &p);
			Offer *x = create_offer(&type, &dest, d, m, y, p);

			if (add_offer_ctrl(ui->ctrl, x) == 0) {
				free_offer(x);
				printf("\nOffer already in repository!\n");
			}
		}
		else if (cmd == 2) {

			printf("Read Update\n");
			readUpdate(&dest2, &d2, &m2, &y2);
			readOffer(&type, &dest, &d, &m, &y, &p);

			if (update_offer_ctrl(ui->ctrl, dest2, d2, m2, y2, type, dest, d, m, y, p) == 0)
				printf("\nNo such an Offer\n");

		}
		else if (cmd == 3) {

			printf("Read Delete\n");
			readUpdate(&dest2, &d2, &m2, &y2);
			if(delete_offer_ctrl(ui->ctrl, dest2, d2, m2, y2) == 0)
				printf("\nNo such an Offer\n");

		}
		else if (cmd == 4) {

			printf("\n");
			if (ui->ctrl->r->arr->n == 0)
				printf("****Empty Repository!****\n");
			print_ctrl(ui->ctrl);
			printf("\n");
		}
		else if (cmd == 5) {

			printf("String: ");
			scanf("%s", &s);

			Offer *x = create_offer("", s, 0, 0, 0, 0);

			printf("\n");
			print_filter(ui, x, cmp_dest);
			printf("\n");

			free_offer(x);
		}
		else if (cmd == 6) {

			printf("Read Type\n");
			readUpdate(&type, &d, &m, &y);

			Offer *x = create_offer(type, "", d, m, y, 0);

			printf("\n");
			print_filter(ui, x, cmp_date);
			printf("\n");

			free_offer(x);
		}
		else if (cmd == 7) {
			
			printf("Type: ");
			scanf("%s", &type);
			printf("Price: ");
			scanf("%d", &p);

			Offer *x = create_offer(type, "", 0, 0, 0, p);

			printf("\n");
			print_filter(ui, x, cmp_price);
			printf("\n");

			free_offer(x);
		}
		else if (cmd == 8) {
			printf("Price: ");
			scanf("%d", &p);

			Offer *x = create_offer("", "", 0, 0, 0, p);

			printf("\n");
			print_filter(ui, x, cmp_price2);
			printf("\n");
			free_offer(x);
		}
		else if (cmd == 9) {

			printf("Sort by: \n");
			printf("1)Type \n");
			printf("2)Destination \n");
			printf("3)Date \n");
			printf("4)Price \n");
			
			p = readIntegerNumber("cmd: ");
			while (p > 5 || p < 1)
				p = readIntegerNumber("cmd: ");

			if (p == 1)
				sort(ui->ctrl, cmp_sortType);
			else if (p == 2)
				sort(ui->ctrl, cmp_sortDestination);
			else if (p == 3)
				sort(ui->ctrl, cmp_sortDate);
			else
				sort(ui->ctrl, cmp_sortPrice);

		}
		else if (cmd == 10) {
			if (!undo(ui->ctrl))
				printf("Unnable to perform undo operation!\n");
		}
		else if (cmd == 11) {
			if (!redo(ui->ctrl))
				printf("Unnable to perform redo operation!\n");
		}
		else if (cmd == 0) {
			break;
		}
		else {
			printf("Invalid Input!\n");
		}

	}
}
