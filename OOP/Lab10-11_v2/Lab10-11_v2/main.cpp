#include "myclass.h"
#include <QtWidgets/QApplication>
#include "controller.h"
#include "repository.h"
#include "HTML_bag.h"

#include "coatValidator.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo;
	HTML_Bag s;
	Controller ctrl(repo, &s, CoatValidator{});


	myClass w(&ctrl);
	w.show();
	return a.exec();
}
