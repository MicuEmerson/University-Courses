#include "myqtclass.h"
#include "repository.h"
#include "controller.h"
#include "coatValidator.h"
#include "HTML_bag.h"
#include <QtWidgets/QApplication>
#include "UI.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo;
	HTML_Bag bag;
	Controller ctrl(repo, &bag, CoatValidator{});
	
	myQtClass w(&ctrl);
	w.show();
	return a.exec();
}
