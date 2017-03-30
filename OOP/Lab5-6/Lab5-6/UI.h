#pragma once
#include "controller.h"
#include <iostream>
#include "dynamicArr.h"
using namespace std;

class UI {

private:
	Controller ctrl;
	int readInteger(const char* message);
public:

	UI(const Controller & controller) : ctrl(controller) {}
	void printMenu();
	void printAdminMenu();
	void printUserMenu();
	void iterate(int size);
	void run();
	void readCoat(int &s, string &c, int &p, int &q, string &ph);
	
};