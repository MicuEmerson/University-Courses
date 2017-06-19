#pragma once
#include <string>

class Teacher {

private:
	std::string name;
	int group;

public:
	Teacher(std::string n, int g) : name(n), group(g) {}
	auto getName() { return name; }
	auto getGroup() { return group; }

};