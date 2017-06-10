#pragma once
#include "book.h"

class Node {

private:
	Book info;
	Node* left;
	Node* right;

public:
	Node() : left(NULL), right(NULL) {}
	Node(Book b) : info(b), left(NULL), right(NULL) {}
	Node(Book b, Node* l, Node* r) : info(b), left(l), right(r) {}

	void setInfo(Book b);
	void setLeft(Node* l);
	void setRight(Node* r);

	Book getInfo();
	Node* getLeft();
	Node* getRight();

	std::string printInfo();
};