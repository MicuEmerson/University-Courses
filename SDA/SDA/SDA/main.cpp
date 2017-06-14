#include <stdlib.h>
#include "book.h"
#include "node.h"
#include "SortedBag.h"
#include "ui.h"
//#include "testing.h"

int main() {
	
	//Testing t;
//	t.runAllTests();
	
	SortedBag sb;
	UI ui(sb);
	ui.run();
	
		
	system("pause");
	return 0;
}