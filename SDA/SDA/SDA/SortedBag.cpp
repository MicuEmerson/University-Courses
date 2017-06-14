#include "SortedBag.h"


Node * SortedBag::getRoot()
{
	return this->root;
}

void SortedBag::setRoot(Node *r)
{
	this->root = r;
}


void SortedBag::add(Book b)
{
	this->setRoot(this->add_rec(this->getRoot(), b));
}

Node* SortedBag::add_rec(Node* r, Book b)
{
	if (r == NULL) 
		r = new Node{b};
	else if (b < r->getInfo())
		r->setLeft(this->add_rec(r->getLeft(), b));
	else
		r->setRight(this->add_rec(r->getRight(), b));

	return r;
}


Node * SortedBag::getMin(Node * r)
{
	if (r->getLeft() == NULL)
		return r;
	getMin(r->getLeft());
}

Iterator SortedBag::iterator(SortedBag sb)
{
	return Iterator(sb);
}

void SortedBag::remove(Book b)
{
	this->setRoot(this->remove_rec(this->getRoot(), b));
}


Node * SortedBag::remove_rec(Node *r, Book b)
{
	if (r == NULL)
		return r;
	else if (b < r->getInfo()) 
		r->setLeft(remove_rec(r->getLeft(), b));
	else if (b > r->getInfo()) 
		r->setRight(remove_rec(r->getRight(), b));
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
			r->setRight(remove_rec(r->getRight(), aux->getInfo()));
			
		}
	}
	return r;
}

bool SortedBag::search(Book b)
{
	return this->search_rec(this->getRoot(), b);
}

bool SortedBag::search_rec(Node* r, Book b)
{
	if (r == NULL)
		return false;
	else if (b == r->getInfo())
		return true;
	else if (b < r->getInfo())
		return search_rec(r->getLeft(), b);
	else 
		return search_rec(r->getRight(), b);
}

int SortedBag::size_rec(Node * r)
{
	if (r == NULL) return 0;
	return size_rec(r->getLeft()) + size_rec(r->getRight()) + 1;
}



int SortedBag::size()
{
	return this->size_rec(this->getRoot());
}


