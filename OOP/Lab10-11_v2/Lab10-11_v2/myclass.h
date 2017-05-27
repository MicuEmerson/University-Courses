#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include "ui_myclass.h"
#include "Controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "controller.h"
#include <QRadioButton>
#include <string>
#include <algorithm>

class myClass : public QWidget
{
	Q_OBJECT

public:
	myClass(Controller *c, QWidget *parent = 0);
	~myClass();

private:
	void guiInit();
	void setSignals();
	Controller *ctrl;

	//Elem upLayout
	QListWidget* repoList;
	QListWidget* shopList;
	QPushButton* insertButton;

	//Elem midLayout
	QLineEdit* sizeCoat;
	QLineEdit* colorCoat;
	QLineEdit* quantityCoat;
	QLineEdit* priceCoat;
	QLineEdit* linkCoat;

	//Elem downLayout
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* filterButton;
	QPushButton* updateButton;

	QRadioButton *b1;
	QRadioButton *b2;

	private slots:
	void sortting();
	void repoInit();
};

#endif // MYCLASS_H
