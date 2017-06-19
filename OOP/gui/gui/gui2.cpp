#include "gui2.hpp"

gui2::gui2(Teacher t, studentRepo *s, QWidget * parent) : teacher(t), repo(s), QWidget(parent) {
	ui.setupUi(this);
	repo->addObserver(this);
	repoInit();
	QWidget::setWindowTitle(t.getName().c_str());
}

gui2::~gui2() {
	repo->removeObserver(this);
}

void gui2::repoInit()
{
	ui.listWidget->clear();
	std::vector<Student>& v = repo->getAll();
	
	for (auto it : v) 
		if (it.getGroup() == teacher.getGroup())
		{
			QString x = QString::fromStdString("Group: " + std::to_string(it.getGroup()) + " | Name: " + it.getName() + " | Grade: " + std::to_string(it.getGrade()));
			QListWidgetItem *item = new QListWidgetItem(x);
			ui.listWidget->addItem(item);
		}


	
}
