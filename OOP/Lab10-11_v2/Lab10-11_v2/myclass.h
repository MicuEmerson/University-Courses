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
#include <QMessageBox>
#include "controller.h"
#include <QRadioButton>
#include <string>
#include <algorithm>
#include "domain.h"
#include "coatValidator.h"
#include "repositoryExceptions.h"
#include <QSpacerItem>


class myClass : public QWidget
{
	Q_OBJECT

public:
	myClass(Controller *c, QWidget *parent = 0);
	~myClass();

private:

	Controller *ctrl;
	void guiInit();
	void bagInit();
	void setSignals();
	void setSignalsFilter();
	int getRepoListSelectedIndex();



	//Elem upLayout
	QListWidget* repoList;
	QListWidget* shopList;
	QPushButton* insertButton;
	QPushButton* photoButton;
	QLineEdit* priceBag;

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
	QPushButton* seeBagButton;

	//radio buttons
	QRadioButton *b1;
	QRadioButton *b2;

	//filter widget button
	QPushButton *filterOk;
	QLineEdit *sizeFilter;
	QWidget * wid;

	//plot
	

	private slots:
	void sortting();
	void repoInit();
	void addNewCoat();
	void deleteCoat();
	void updateCoat();
	void filter();
	void filterSize();
	void addToBag();
	void seePhoto();
	void seeBagContent();
	void plot();


};

#endif // MYCLASS_H