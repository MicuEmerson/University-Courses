#pragma once
#include <iostream>
#include "SortedBag.h"
#include <string>
#include "book.h"
#include <fstream>

using namespace std;

class UI {

private:
	SortedBag sb;
public:
	UI(SortedBag s) : sb(s) {}

	void run();
	Book readBook();
	void printMenu();
	//void readFromFile();

};