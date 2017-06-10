#pragma once
#include "node.h"
#include <iostream>
#include <queue>


class Iterator;

class SortedBag {

private:
	Node* root;
public:
	SortedBag() : root(NULL) {}
	SortedBag(Node* r) : root(r) {}

	Node* add(Node* r, Book b);
	Node* remove(Node*r, Book b);
	bool search(Node* r, Book b);
	void afisare(Node* r);
	int size(Node *r);

	Node* getRoot();
	void setRoot(Node *r);
	Node* getMin(Node *r);
	Iterator iterator(SortedBag sb);

};



class Iterator {

private:
	Node* currentNode;
	SortedBag sb;
	std::queue<Node*> Q;

public:
	Iterator() {}
	Iterator(SortedBag s) : sb(s) {

		this->currentNode = sb.getRoot();
		this->inOrder(currentNode);
	}

	void inOrder(Node* r) {
		if (r == NULL) return;
		inOrder(r->getLeft());
		this->Q.push(r);
		inOrder(r->getRight());
	}

	bool valid() {
		if (currentNode == NULL)
			return false;
		return true;
	}

	void nextt() {
		if (Q.empty()) {
			currentNode = NULL;
			return;
		}
		this->currentNode = Q.front();
		Q.pop();
	}

	Node* getCurrent() {
		return currentNode;
	}

};
