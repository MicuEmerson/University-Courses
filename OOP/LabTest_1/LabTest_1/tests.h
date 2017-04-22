#pragma once
#include <assert.h>
#include "domain.h"
#include "repository.h"
#include "domain.h"

void testing() {

	Repository repo;
	Project a{ "Stairs", "Flin", 15, 4, 2018, 18, false };
	Project b{ "Website", "Spital", 5, 10,2015, 100, true };
	Project c{ "Aplicatie", "Ubb", 2, 3,2017, 500, false };
	Project d{ "Game", "Google", 3, 15,2017, 100, false };
	Project e{ "Music", "Facebook", 12, 15,2015, 100, true };
	assert(repo.add(a) == true);
	assert(repo.add(b) == true);
	assert(repo.add(c) == true);
	assert(repo.add(d) == true);
	assert(repo.add(e) == true);

	Controller ctrl(repo);
	assert(ctrl.cost_ctrl() == 200);
	Project f{ "Musiaaac", "Facaaaebook", 12, 15,2015, 1000, true };
	ctrl.add_ctrl(f);
	assert(ctrl.cost_ctrl() == 1200);


}

