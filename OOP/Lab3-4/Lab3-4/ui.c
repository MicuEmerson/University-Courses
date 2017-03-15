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
	printf("8) Undo\n");
	printf("9) Redo\n");
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

void print_filter_destination(UI *ui, char *s) {

	OfferRepo *repo = filter_destination(ui->ctrl, s);
	if (repo->arr->n == 0) 
		printf("No such an offer in repository\n");
	else 
		print_repo(repo);

	free_repo(repo);
}

void print_filter_date(UI *ui, char *type, int d, int m, int y) {

	OfferRepo *repo = filter_date(ui->ctrl, type, d, m, y);
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
			print_ctrl(ui->ctrl);
			printf("\n");
		}
		else if (cmd == 5) {

			printf("String: ");
			scanf("%s", &s);

			printf("\n");
			print_filter_destination(ui, s);
			printf("\n");

		}
		else if (cmd == 6) {

			printf("Read Type\n");
			readUpdate(&type, &d, &m, &y);

			printf("\n");
			print_filter_date(ui, type, d, m, y);
			printf("\n");

		}
		else if (cmd == 7) {
			
			printf("Type: ");
			scanf("%s", &type);
			printf("Price: ");
			scanf("%d", &p);

			printf("\n");
			filter_price(ui->ctrl, &type, p);
			printf("\n");
		}
		else if (cmd == 8) {
			;
		}
		else if (cmd == 9) {
			;
		}
		else if (cmd == 0) {
			break;
		}
		else {
			printf("Invalid Input!\n");
		}

	}
}
