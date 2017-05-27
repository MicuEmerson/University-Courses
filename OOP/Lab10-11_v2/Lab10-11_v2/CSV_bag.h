#pragma once
#include "shopBag.h"

class CSV_Bag : public ShopBag {

public:

	void writeToFile_bag() override {
		std::ofstream fout("bagRepo.csv");

		for (auto it : v)
			fout << it;
	}

	void openThings() {
		this->writeToFile_bag();
		ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Microsoft Office\\Office14\\EXCEL.exe", "bagRepo.csv", NULL, SW_SHOWMAXIMIZED);
	}

};