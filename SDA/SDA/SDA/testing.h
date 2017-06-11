#pragma once
#include <vector>
#include <string>
#include <assert.h>
#include "book.h"
#include "node.h"
#include "SortedBag.h"

class Testing{

public:
	void runAllTests();
private:
	void testBook();
	void testNode();
	void testSortedBag();
};