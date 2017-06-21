#pragma once
#include <string>

class SourceFile {

private:
	std::string name;
	std::string status;
	std::string creator;
	std::string reviewer;
public:
	SourceFile(std::string n, std::string s, std::string c, std::string r) : name(n), status(s), creator(c), reviewer(r) {}
	auto getName() { return name; }
	auto getStatus() { return status; }
	auto getCreator() { return creator; }
	auto getReviewer() { return reviewer; }
	void setStatus(std::string s) { status = s; }
	void setReviewer(std::string s) { reviewer = s; }
};
