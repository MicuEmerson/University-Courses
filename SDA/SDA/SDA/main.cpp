#include <iostream>
#include <stdlib.h>
#include "book.h"
#include "node.h"
#include "SortedBag.h"


using namespace std;

int main() {
	
	
	Book b("bb", "aaaa");
	Book a("ba", "aaaaa");
	Book c("x", "AA");
	Node *nod = new Node{ b };
	
	SortedBag bag(nod);
	
	bag.setRoot(bag.add(bag.getRoot(), Book("Ana", "Are Mere")));
	bag.setRoot(bag.add(bag.getRoot(), Book("Ana", "Are Mere")));
	bag.setRoot(bag.add(bag.getRoot(), b));

	bag.setRoot(bag.add(bag.getRoot(), b));

	bag.afisare(bag.getRoot());
	cout << endl;
	
	bag.setRoot(bag.remove(bag.getRoot(), b));
	bag.setRoot(bag.remove(bag.getRoot(), b));
	bag.afisare(bag.getRoot());

	Iterator iter = bag.iterator(bag);

	while (iter.valid()) {
		cout << iter.getCurrent()->printInfo();
		iter.nextt();
	}
	

	system("pause");
	return 0;
}