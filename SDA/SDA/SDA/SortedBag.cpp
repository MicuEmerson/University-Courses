#include "SortedBag.h"


Node * SortedBag::getRoot()
{
	return this->root;
}

void SortedBag::setRoot(Node *r)
{
	this->root = r;
}

Node* SortedBag::add(Node* r, Book b)
{
	if (r == NULL) 
		r = new Node{b};
	else if (b.getAuthor() < r->getInfo().getAuthor())
		r->setLeft(this->add(r->getLeft(), b));
	else
		r->setRight(this->add(r->getRight(), b));

	return r;
}

Node * SortedBag::getMin(Node * r)
{
	if (r->getLeft() == NULL)
		return r;
	return getMin(r->getLeft());
}

Iterator SortedBag::iterator(SortedBag sb)
{
	return Iterator(sb);
}

void SortedBag::afisare(Node* r)
{   
	if (r == NULL) return;
	this->afisare(r->getLeft());
	std::cout << r->printInfo();
	this->afisare(r->getRight());
}

Node * SortedBag::remove(Node *r, Book b)
{
	if (r == NULL)
		return r;
	else if (b < r->getInfo())
		r->setLeft(remove(r->getLeft(), b));
	else if (b > r->getInfo())
		r->setRight(remove(r->getRight(), b));
	else {

		if (r->getLeft() == NULL && r->getRight() == NULL) {
			delete r;
			r = NULL;
		}
		else if (r->getRight() == NULL) {
			Node* aux = r;
			r = r->getLeft();
			delete aux;
		}
		else if (r->getLeft() == NULL) {
			Node* aux = r;
			r = r->getRight();
			delete aux;
		}
		else {
			Node* aux = getMin(r->getRight());
			r->setInfo(aux->getInfo());
			r->setRight(remove(r->getRight(), aux->getInfo()));
		}

		return r;
	}
}

bool SortedBag::search(Node* r, Book b)
{
	if (r == NULL)
		return false;
	else if (b == r->getInfo())
		return true;
	else if (b < r->getInfo())
		return search(r->getLeft(), b);
	else 
		return search(r->getRight(), b);
}

int SortedBag::size(Node* r)
{
	if (r == NULL) return 0;
	return size(r->getLeft()) + size(r->getRight()) + 1;
}



