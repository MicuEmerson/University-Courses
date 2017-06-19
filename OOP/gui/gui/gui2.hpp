#pragma once
#include <QWidget>
#include "ui_gui2.h"
#include "teacher.h"
#include "studentRepo.h"
#include "student.h"
#include <string>
#include <vector>

class gui2 : public QWidget, public Observer {
	Q_OBJECT

public:
	gui2(Teacher t, studentRepo *r, QWidget * parent = Q_NULLPTR);
	~gui2();
	void repoInit();
	void update() override { this->repoInit(); }

private:
	Ui::gui2 ui;
	Teacher teacher;
	studentRepo *repo;

};
