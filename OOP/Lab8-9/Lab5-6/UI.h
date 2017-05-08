#pragma once
#include "controller.h"
#include <iostream>
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
	int getNext(vector<Coat>& vec, int pos, int size);
	void printIterate(int x);
	void writeToFile_UI() { this->ctrl.writeToFile_repo(); }
	void readFromFile_UI() { this->ctrl.readFromFile_repo(); }
};