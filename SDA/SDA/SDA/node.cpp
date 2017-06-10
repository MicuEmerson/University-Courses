#include "node.h"

void Node::setInfo(Book b)
{
	this->info = b;
}

void Node::setLeft(Node * l)
{
	this->left = l;
}

void Node::setRight(Node * r)
{
	this->right = r;
}

Book Node::getInfo()
{
	return this->info;
}

Node * Node::getLeft()
{
	return this->left;
}

Node * Node::getRight()
{
	return this->right;
}

std::string Node::printInfo()
{
	return "Author: " + this->info.getAuthor() + " | Name: " + this->info.getName() + "\n";
}
