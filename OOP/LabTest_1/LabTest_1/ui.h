#pragma once
#include "controller.h"
#include "domain.h"
#include <iostream>
using namespace std;
class UI {

private:
	Controller ctrl;
public:
	UI(Controller c): ctrl(c) {}
	void run();
	void print_menu();


};