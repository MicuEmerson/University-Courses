#pragma once
#include <string>
#include <vector>
#include "sourceFile.h"
#include "programmer.h"
#include <fstream>
#include <sstream>
#include "observator.h"
#include <algorithm>
#include <qdebug.h>

class Repository : public Observabil{

private:
	std::vector<Programmer> v1;
	std::vector<SourceFile> v2;
public:

	Repository(){ 
	this->readFromFile_P();
	this->readFromFile_S();
	}

	~Repository() {
		this->writeToFile(); 
		//this->writeToFile_2();

	 } 

	std::vector<Programmer> & getAll_P() { return v1; }
	std::vector<SourceFile> & getAll_S() { return v2; }
	/*
		add
		INPUT: string name
			   string author
		OUTPUT:
	        N\A
		We simply add a new SourceFile in our repository in v2 vector and also check if ther the element is in the vector already or not
		Also we check for input name to not be empty.

	*/
	void add(std::string name, std::string author) {

		if (name == "")
			throw std::exception("Name field is empty!");
		for(auto it: v2)
			if(it.getName() == name )
				throw std::exception("This elem is already in repo!");
		
		v2.push_back(SourceFile(name, "not_revised", author, "-"));
		this->notify();
	}
	/*
	  Review
	  INPUT: string name
	         striing author
	  OUTPUT:
			1  succesfully changed status or 0 if we fail
	   
	*/
	int review(std::string name, std::string author) {
		
		for(auto &it: v2)
			if(name == it.getName())
				if (it.getStatus() == "not_revised" && it.getCreator() != author) {
					it.setReviewer(author);
					it.setStatus("revised");
					this->notify();
					return 1;
				}
		return 0;
	}



private:
	void readFromFile_P() {
		std::ifstream fin("text1.txt");
		std::string s;
		while (getline(fin,s)) {
			std::string x;
			std::stringstream ss(s);
			std::vector<std::string> rez;
			while (getline(ss, x, ' ')) {
				rez.push_back(x);
			}
			if (rez.size() != 3)
				return;
			v1.push_back(Programmer(rez[0], atoi(rez[1].c_str()), atoi(rez[2].c_str())));
		}
	}

	void readFromFile_S() {
		std::ifstream fin("text2.txt");
		std::string s;
		while (getline(fin, s)) {
			std::string x;
			std::stringstream ss(s);
			std::vector<std::string> rez;
			while (getline(ss, x, ' ')) {
				rez.push_back(x);
			}
			if (rez.size() != 4)
				return;
			v2.push_back(SourceFile(rez[0], rez[1], rez[2], rez[3]));
		}
	}

	void writeToFile() {
		std::ofstream fout("text2.txt");
		for (auto it : v2)
			fout << it.getName() << " " << it.getStatus() << " " << it.getCreator() << " " << it.getReviewer() << "\n";
	}

	void writeToFile_2() {
		std::ofstream fout("text1.txt");
		for (auto it : v1)
			fout << it.getName() << " " << it.getNrFields() << " " << it.getTotal() << "\n";
	}




};