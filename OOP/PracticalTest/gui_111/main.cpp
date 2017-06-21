#include "gui_111.h"
#include <QtWidgets/QApplication>
#include "programmer.h"
#include "sourceFile.h"
#include "repository4.h"
#include "observator.h"
#include "assert.h"

void tests() {

	Repository r;
	r.add("AAA", "BBB");
	assert(r.getAll_S().size() == 1);
	assert(r.getAll_S().size() == 1);
	r.add("CCC", "DDD");
	assert(r.getAll_S().size() == 2);

	assert(r.review("AAA", "EEE") == 1);
	assert(r.review("QQQ", "EEE") == 0);
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//tests();
	
	Repository r;
	
	for (auto it : r.getAll_P()) {
		Programmer *x = new Programmer(it.getName(), it.getNrFields(), it.getTotal());
		gui_111 *k = new gui_111(x, &r);
		k->show();
	}

	
	return a.exec();
	
}
