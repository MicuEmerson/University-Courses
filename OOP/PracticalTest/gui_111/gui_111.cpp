#include "gui_111.h"

gui_111::gui_111(Programmer *p, Repository *r, QWidget *parent)
	: programmer(p), repo(r), QWidget(parent)
{
	ui.setupUi(this);
	QWidget::setWindowTitle(QString::fromStdString(programmer->getName()));
	repoInit();
	setSignals();
	this->repo->addObs(this);
	ui.lineEdit->setText(QString::fromStdString(std::to_string(programmer->getNrFields())));
	ui.lineEdit_2->setText(QString::fromStdString(std::to_string(programmer->getTotal())));
}

gui_111::~gui_111()
{
	this->repo->removeObs(this);
}

void gui_111::repoInit()
{
	ui.listWidget->clear();
	auto v = repo->getAll_S();
	sort(v.begin(), v.end(), [](auto a, auto b) {return a.getName() < b.getName(); });
	int k = 0;
	for (auto it : v) {
		QString x = QString::fromStdString("Name: " + it.getName() + ", Status: " + it.getStatus() + ", Creator: " + it.getCreator() + ", Reviwer: " + it.getReviewer());
		QListWidgetItem *item = new QListWidgetItem(x);
		
		if (it.getStatus() == "revised") {
			item->setBackground(Qt::green);
			QFont f;
		
			f.setBold(true);
			item->setFont(f);
		}

		ui.listWidget->addItem(item);

	}

}

void gui_111::setSignals()
{
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(add_GUI()));
	QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(review_GUI()));
}

void gui_111::review_GUI()
{
	std::string name = ui.lineEdit_3->text().toStdString();
	int rez = repo->review(name, programmer->getName());
	
	if (rez) {
		programmer->setTotal(programmer->getNrFields() + 1);
		ui.lineEdit->setText(QString::fromStdString(std::to_string(programmer->getNrFields())));
		ui.lineEdit_2->setText(QString::fromStdString(std::to_string(programmer->getTotal())));

		if (programmer->getNrFields() == programmer->getTotal()) {
			QMessageBox x;
			x.information(0, "Info", QString::fromStdString("CONGRATULATION"));
		}
	}
	
}

void gui_111::add_GUI()
{
	
	std::string name = ui.lineEdit_3->text().toStdString();
	try {
		repo->add(name, programmer->getName());
	}
	catch (std::exception &g) {
		QMessageBox x;
		x.critical(0, "error", QString::fromStdString(g.what()));
	}
}
