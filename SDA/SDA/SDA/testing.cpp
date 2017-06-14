#include "testing.h"

void Testing::runAllTests()
{
	this->testBook();
	this->testNode();
	this->testSortedBag();
}

void Testing::testBook()
{
	Book x{ "AAA", "BBB" };
	Book q{ "AAA", "AAA" };

	assert(x.getAuthor() == "AAA");
	assert(x.getName() == "BBB");

	x.setAuthor("aaa");
	x.setName("bbb");
	
	assert(x.getAuthor() != "AAA");
	assert(x.getName() != "BBB");

	assert(x.getAuthor() == "aaa");
	assert(x.getName() == "bbb");

	Book y{ "CCC", "DDD" };
	Book k{ "CCC", "AAA" };
	Book j{ "DDD", "AAA" };
	assert(x > y);
	assert(y < x);
	assert(y > k);
	assert(!(y < k));
	assert(x > q);
	assert(!(x < q));
	assert(!(x < y));
	assert(!(y > x));
	assert(y < x);
	assert(!(y > j));
	assert(x == x);

	
}

void Testing::testNode()
{ 
	Book a{ "bbb", "aaa" };
	Book b{ "aaa", "bbb" };
	Node x(b);

	assert(x.getInfo() == b);
	assert(x.getLeft() == NULL);
	assert(x.getRight() == NULL);

	x.setInfo(a);
	assert(x.getInfo() == a);

	Node *st = new Node;
	Node *dr = new Node;
	x.setLeft(st);
	x.setRight(dr);

	assert(x.getLeft() == st);
	assert(x.getRight() == dr);
	x.printInfo();
	

}

void Testing::testSortedBag()
{
	/*
	Book b{ "aaa", "bbb" };
	Book a{ "bbb", "bbb" };
	Book c{ "ccc", "bbb" };

	SortedBag sb;
	sb.setRoot(sb.add(sb.getRoot(), b));
	assert(sb.size(sb.getRoot()) == 1);
	sb.setRoot(sb.remove(sb.getRoot(), b));
	assert(sb.size(sb.getRoot()) == 0);
	assert(sb.search(sb.getRoot(), b) == false);
	sb.setRoot(sb.add(sb.getRoot(), b));
	assert(sb.search(sb.getRoot(), b) == true);
	assert(sb.getMin(sb.getRoot()) == sb.getRoot());
	sb.setRoot(sb.getRoot());
	sb.setRoot(sb.add(sb.getRoot(), b));
	sb.setRoot(sb.add(sb.getRoot(), c));
	sb.setRoot(sb.add(sb.getRoot(), a));
	sb.setRoot(sb.add(sb.getRoot(), b));
	sb.setRoot(sb.add(sb.getRoot(), c));
	sb.setRoot(sb.add(sb.getRoot(), a));

	Book d{ "DDD", "bbb" };
	Node* miny = sb.getMin(sb.getRoot());
	assert(sb.getMin(sb.getRoot()) == miny);
	sb.setRoot(sb.add(sb.getRoot(), d));
	miny = sb.getMin(sb.getRoot());
	assert(sb.getMin(sb.getRoot()) == miny);

	assert(sb.search(sb.getRoot(), a) == true);
	assert(sb.search(sb.getRoot(), b) == true);
	assert(sb.search(sb.getRoot(), c) == true);
	assert(sb.search(sb.getRoot(), d) == true);

	sb.setRoot(sb.remove(sb.getRoot(), d));
	sb.setRoot(sb.remove(sb.getRoot(), a));
	sb.setRoot(sb.remove(sb.getRoot(), b));
	sb.setRoot(sb.remove(sb.getRoot(), c));


	sb.setRoot(sb.remove(sb.getRoot(), Book("aa", "bb")));
	
	
	Iterator iter = sb.iterator(sb);
	iter.next();
	while (iter.valid()) {
		iter.getCurrent();
		iter.next();
	}
	
	SortedBag sbbb;
	sbbb.setRoot(sbbb.add(sbbb.getRoot(), Book("C", "a")));
	sbbb.setRoot(sbbb.add(sbbb.getRoot(), Book("A", "a")));
	sbbb.setRoot(sbbb.add(sbbb.getRoot(), Book("B", "a")));
	sbbb.setRoot(sbbb.remove(sbbb.getRoot(), Book("A", "a")));
	
	*/
	;


}
