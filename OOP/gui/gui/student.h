#pragma once
#include <string>


class Student {

private:
	int id;
	std::string name;
	int group;
	double grade;
	std::string teacher;

public:
	Student(int i, std::string n, int g, double d, std::string t) : id(i), name(n), group(g), grade(d), teacher(t) {}
	int getId() { return id; }
	auto getName() { return name; }
	auto getGroup() { return group; }
	auto getGrade() { return grade; }
	auto getTeacher() { return teacher; }
	void setGrade(double g) { grade = g; }
	void setTeacher(std::string t) { teacher = t; }
	bool operator==(Student x) { return id == x.getId(); }

};