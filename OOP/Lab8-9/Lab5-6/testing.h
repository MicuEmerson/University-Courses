#pragma once
#include "shopBag.h"
#include "controller.h"
#include "repository.h"

#include <assert.h>

void tests() {

	
	Coat a(33, "blue", 65, 3, "https://s-media-cache-ak0.pinimg.com/736x/00/4e/7b/004e7b590432e8a49b260141756785fe.jpg");
	Coat b{ 33, "red", 190, 2, "http://wardrobelooks.com/wp-content/uploads/2014/01/red-coats-for-women-1.jpg" };
	Coat c{ 34, "yellow",100, 1, "https://s-media-cache-ak0.pinimg.com/564x/50/19/53/501953610c6c185409765401e7f43465.jpg" };
	Coat d{ 33, "green", 89, 2, "http://www.justwomenfashion.com/wp-content/uploads/2016/04/new-winter-long-coat-women-double-breasted-fashion-woman-wool-green-coats-spain-ukraine-manteau.jpg" };
	Coat e{ 34, "pink", 59, 3, "https://s-media-cache-ak0.pinimg.com/originals/81/53/02/815302195da2d512ceaa56aea81faa1d.jpg" };

	assert(a.get_color() == "blue");
	assert(a.get_photo() == "https://s-media-cache-ak0.pinimg.com/736x/00/4e/7b/004e7b590432e8a49b260141756785fe.jpg");
	assert(a.get_price() == 65);
	assert(a.get_quantity() == 3);
	assert(a.get_size() == 33);
	assert(a == a);
	a.set_color("1");
	a.set_photo("1");
	a.set_price(1);
	a.set_quantity(1);
	a.set_size(1);
	a.print_coat();
	a.see_photo();

	Repository r;
	Controller ctrl(r);
	
	assert(ctrl.add_repo(a) == true);
	assert(ctrl.add_repo(a) == false);

	assert(ctrl.del_repo(a) == true);
	assert(ctrl.del_repo(a) == false);
    
	ctrl.add_repo(b);
	assert(ctrl.update_repo(b, c) == true);
	assert(ctrl.update_repo(b, c) == false);
	
	
	ctrl.add_bag(d);
	assert(ctrl.get_price_bag() == 89);

	ctrl.print_bag();
	ctrl.print_repo();
	auto v = ctrl.getAll_repo();


	
	

}
