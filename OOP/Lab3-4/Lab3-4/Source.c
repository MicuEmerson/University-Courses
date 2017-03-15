#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "domain.h"
#include "repository.h"
#include "controller.h"
#include "ui.h"
#include "dynamic_array.h"
#include "dynamic_array2.h"


int main() {

	test_controller();
	test_repo();

	OfferRepo *r = create_repo();
	Controller *ctrl = create_ctrl(r);
	
	Offer *a = create_offer("Seaside", "Maldive", 11, 12, 2017, 825);	
	Offer *b = create_offer("Mountain", "Cavnic", 12, 11, 2017, 350);
	Offer *c = create_offer("CityBreak", "London", 13, 10, 2017, 200);	
	Offer *d = create_offer("Mountain", "Retezat", 14, 9, 2017, 250);
	Offer *e = create_offer("Seaside", "Rimini", 15, 8, 2017, 400);
	Offer *f = create_offer("CityBreak", "Tokyo", 16, 7, 2017, 1300);
	Offer *g = create_offer("CityBreak", "Barcelona", 7, 6, 2017, 455);
	Offer *h = create_offer("Mountain", "Feleacu", 18, 5, 2017, 150);
	Offer *i = create_offer("Seaside", "Black Sea", 19, 4, 2017, 350);
	Offer *k = create_offer("CityBreak", "New York", 10, 3, 2017, 1500);
	
	add_offer_ctrl(ctrl, a);
	add_offer_ctrl(ctrl, b);
	add_offer_ctrl(ctrl, c);
	add_offer_ctrl(ctrl, d);
	add_offer_ctrl(ctrl, e);
	add_offer_ctrl(ctrl, f);
	add_offer_ctrl(ctrl, g);
	add_offer_ctrl(ctrl, h);
	add_offer_ctrl(ctrl, i);
	add_offer_ctrl(ctrl, k);
	

	UI *ui = create_ui(ctrl);
	start_ui(ui);
	delete_ui(ui);
	
	_CrtDumpMemoryLeaks();
	system("pause");

	return 0;
}	