#ifndef MYQTCLASS_H
#define MYQTCLASS_H

#include <QtWidgets/QMainWindow>
#include "ui_myqtclass.h"
#include <qpushbutton.h>
#include "Controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <string>
#include <string.h>

class myQtClass : public QWidget
{
	Q_OBJECT

public:
	myQtClass(Controller *c, QWidget *parent = 0);
	~myQtClass();

private:
	QListWidget * repoList;
	Controller * ctrl;
	QLineEdit *sizeEdit;
	void initGui();
	void initRepo();

};

#endif // MYQTCLASS_H
