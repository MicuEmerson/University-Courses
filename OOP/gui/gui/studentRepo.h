#pragma once
#include "student.h"
#include "observer.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <qdebug.h>

class studentRepo : public Observable {

private:
	std::vector<Student> v;
public:

	studentRepo() { readFromFile(); }
	~studentRepo() { writeToFile(); }

	void add(Student x) { this->v.push_back(x); this->notify(); }

	void remove(Student x) { std::remove(v.begin(), v.end(), x); this->notify(); }

	bool find(Student x) {
		for (auto it : v)
			if (it == x)
				return true;
		return false;
	}

	std::vector<Student>& getAll() { return v; }

private:
	void readFromFile() {
		std::ifstream fin("text.txt");
		std::string s;
		
		while (getline(fin, s)) {

			std::stringstream ss(s);
			std::string x;
			std::vector <std::string> rez;

			while (getline(ss, x, ' ')) {
				rez.push_back(x);
			}
			if (rez.size() != 5)
				return;

			v.push_back(Student(atoi(rez[0].c_str()), rez[1], atoi(rez[2].c_str()), std::stod(rez[3].c_str()), rez[4]));
		}

	}
	
	void writeToFile() {
		std::ofstream fout("text.txt");
		qDebug() << "AAAA";
		for (auto it : v)
			fout << it.getId() << " " << it.getName() << " " << it.getGroup() << " " << it.getGrade() << " " << it.getTeacher() << "\n";
	}

};