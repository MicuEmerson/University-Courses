#include "gui.h"

gui::gui(studentRepo *r, QWidget *parent)
	: repo(r), QWidget(parent)
{
	ui.setupUi(this);
	repo->addObserver(this);
	repoInit();
	setSignals();

}

gui::~gui()
{
	repo->removeObserver(this);
}

void gui::repoInit()
{
	ui.listWidget->clear();
	std::vector<Student>& v = repo->getAll();
	sort(v.begin(), v.end(), [](Student a, Student b) {
	    
		if (a.getGroup() < b.getGroup())
			return true;
		if (a.getGroup() == b.getGroup())
			return a.getName() < b.getName();
		else
			return false;

	});

	for (auto it : v) {
		QString x =  QString::fromStdString("Group: " + std::to_string(it.getGroup()) + " | Name: " + it.getName() + " | Grade: " + std::to_string(it.getGrade()));
		QListWidgetItem *item = new QListWidgetItem(x);
		ui.listWidget->addItem(item);
	}
}

void gui::update()
{
	repoInit();
}

void gui::setSignals()
{

	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(addStudent_gui()));
}

void gui::addStudent_gui()
{
	std::string name = ui.lineEdit->text().toStdString();
	int group = atoi(ui.lineEdit_2->text().toStdString().c_str());
	qDebug() << "Emy";

	repo->add(Student(rand() % 100, name, group, 1, ""));
	repoInit();
}

