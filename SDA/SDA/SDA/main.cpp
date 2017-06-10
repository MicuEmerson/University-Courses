#include <stdlib.h>
#include "book.h"
#include "node.h"
#include "SortedBag.h"
#include "ui.h"


int main() {


	SortedBag sb;

	UI ui(sb);
	ui.run();

	system("pause");
	return 0;
}