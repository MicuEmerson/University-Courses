#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QWidget>
#include "ui_gui.h"
#include "observer.h"
#include "studentRepo.h"
#include <string>
#include <vector>
#include <algorithm>
#include <qdebug.h>

class gui : public QWidget, public Observer
{
	Q_OBJECT

public:
	gui(studentRepo *r, QWidget *parent = 0);
	~gui();
	void repoInit();
	void update() override;

private:
	Ui::guiClass ui;
	studentRepo *repo;
	void setSignals();

private slots:
	void addStudent_gui();
};

#endif // GUI_H
