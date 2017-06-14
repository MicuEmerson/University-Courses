#pragma once
#include "node.h"
#include <iostream>
#include <queue>


class Iterator;

class SortedBag {

private:

	Node* root;
	Node* add_rec(Node *r, Book b);
	Node* remove_rec(Node *r, Book b);
	bool search_rec(Node* r, Book b);
	int size_rec(Node* r);
	void setRoot(Node *r);
	Node* getMin(Node *r);
	Node* getRoot();
	
public:

	SortedBag() : root(NULL) {}
	SortedBag(Node* r) : root(r) {}
	
	void add(Book b);
	void remove(Book b);
	bool search(Book b);
	int size();

	
	friend class Iterator;
	Iterator iterator(SortedBag sb);
	
};



class Iterator {

private:
	Node* currentNode;
	SortedBag sb;
	std::queue<Node*> Q;

	void inOrder(Node* r) {
		if (r == NULL) return;
		inOrder(r->getLeft());
		this->Q.push(r);
		inOrder(r->getRight());
	}

public:
	Iterator() {}
	Iterator(SortedBag s) : sb(s) {

		this->currentNode = sb.getRoot();
		this->inOrder(currentNode);
	}


	bool valid() {
		if (currentNode == NULL)
			return false;
		return true;
	}

	void next() {
		if (Q.empty()) {
			currentNode = NULL;
			return;
		}
		this->currentNode = Q.front();
		Q.pop();
	}

	Book getCurrent() {
		return currentNode->getInfo();
	}

};
