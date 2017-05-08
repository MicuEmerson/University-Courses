#pragma once
#include "shopBag.h"

class HTML_Bag : public ShopBag {

public:

	void writeToFile_bag() override {
		std::ofstream fout("bagRepo.html");

		std::string rez = "<!DOCTYPE html>\n";
		rez += "<html>\n";
		rez += "<head>\n";
		rez += "<title>ShopBag</title>\n";
		rez += "</head>\n";
		rez += "<body>\n";
		rez += "<table border=\"1\">\n";
		rez += "<tr>\n";
		rez += "<td>Size</td>\n";
		rez += "<td>Color</td>\n";
		rez += "<td>Price</td>\n";
		rez += "<td>Link</td>\n";
		rez += "</tr>\n";

		int size;
		std::string color;
		int price;
		int quantity;
		std::string photo;

		for (auto it : v) {

			rez += "<tr>\n";
			std::stringstream ss1, ss2;
			
			ss1 << it.get_size();
			ss2 << it.get_price();
		    

			rez += "<td>" + ss1.str() + "</td>\n";
			rez += "<td>" + it.get_color() + "</td>\n";
			rez += "<td>" + ss2.str() + "</td>\n";
			rez += "<td><a href=\"" + it.get_photo() + "\">" + "Link" + "</a></td>\n";

			rez += "</tr>\n";
		}

		rez += "</table>";
		rez += "</body>\n";
		rez += "</html>\n";
		
		fout << rez;
	}

	void openThings() {

		this->writeToFile_bag();
		ShellExecuteA(NULL, NULL, "chrome.exe", "bagRepo.html", NULL, SW_SHOWMAXIMIZED);
	}

};