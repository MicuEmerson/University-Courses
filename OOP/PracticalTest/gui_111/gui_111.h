#ifndef GUI_111_H
#define GUI_111_H

#include <QtWidgets/QWidget>
#include "ui_gui_111.h"
#include "programmer.h"
#include <string>
#include <qdebug.h>
#include <qmessagebox.h>
#include "repository4.h"
#include <unordered_map>
class gui_111 : public QWidget, public Observator
{
	Q_OBJECT

public:
	gui_111(Programmer *p, Repository *r, QWidget *parent = 0);
	~gui_111();
	void repoInit();
	void update() override { this->repoInit(); }
	void setSignals();

public slots:
	void add_GUI();
	void review_GUI();

private:
	Ui::gui_111Class ui;
	Programmer *programmer;
	Repository *repo;
	std::unordered_map<std::string, bool> myMap;
};

#endif // GUI_111_H
