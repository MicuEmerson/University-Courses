#include "gui.h"
#include "gui2.hpp"
#include <QtWidgets/QApplication>
#include "studentRepo.h"
#include "teacher.h"

int main(int argc, char *argv[])
{ 
	QApplication a(argc, argv);
	studentRepo sRepo;
	gui w(&sRepo);
	
	gui2 k(Teacher("Iuliana", 915), &sRepo);
	gui2 q(Teacher("Mihoc", 914), &sRepo);
	
	
	k.show();
 	w.show();	
	q.show();
	return a.exec();
}
