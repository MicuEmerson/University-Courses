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



	Repository r;
	Controller ctrl(r);
	assert(ctrl.add_repo(a) == true);
	assert(ctrl.add_repo(b) == true);
	assert(ctrl.add_repo(a) == false);
	ctrl.add_bag(a);
	assert(ctrl.get_price_bag() == 65);
	ctrl.add_bag(b);

	assert(ctrl.get_price_bag() == 255);
	ctrl.add_bag(c);

	assert(ctrl.update_repo(a, c) == true);
	assert(ctrl.del_repo(c) == true);
	

}
