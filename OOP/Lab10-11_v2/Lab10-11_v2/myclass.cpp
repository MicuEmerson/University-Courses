#include "myclass.h"

myClass::myClass(Controller *c, QWidget *parent)
	: ctrl(c), QWidget(parent) 
{
	this->guiInit();
	this->repoInit();
	
}

myClass::~myClass()
{
	 

}

void myClass::guiInit()
{
	QVBoxLayout * mainLay = new QVBoxLayout{this};
	
	// up part
	QHBoxLayout * upLay = new QHBoxLayout{};
	repoList = new QListWidget{};
	insertButton = new QPushButton{"Insert"};
	shopList = new QListWidget{};
    
	upLay->addWidget(repoList);
	upLay->addWidget(insertButton);
	upLay->addWidget(shopList);

	// middle part
	QFormLayout * middleLay = new QFormLayout{};
	sizeCoat = new QLineEdit{};
	colorCoat = new QLineEdit{};
	quantityCoat = new QLineEdit{};
	priceCoat = new QLineEdit{};
	linkCoat = new QLineEdit{};
	
	middleLay->addRow("Size: ", sizeCoat);
	middleLay->addRow("Color: ", colorCoat);
	middleLay->addRow("Quantity: ", quantityCoat);
	middleLay->addRow("Price: ", priceCoat);
	middleLay->addRow("Link: ", linkCoat);

	//down part
	QHBoxLayout * downLay = new QHBoxLayout{};
	addButton = new QPushButton{"Add"};
	deleteButton = new QPushButton{"Delete"};
	updateButton = new QPushButton{"Update"};
	filterButton = new QPushButton{ "Filter" };

	downLay->addWidget(addButton);
	downLay->addWidget(deleteButton);
	downLay->addWidget(updateButton);
	downLay->addWidget(filterButton);


	//butoane

	QHBoxLayout * buttonLay = new QHBoxLayout{};
	b1 = new QRadioButton{ "Suffle" }; 
	b2 = new QRadioButton{ "Sorted" };
	buttonLay->addWidget(b1);
	buttonLay->addWidget(b2);


	//we insert all layount in main layout using widgets
	QWidget * up = new QWidget{};
	up->setLayout(upLay);

	QWidget * middle = new QWidget{};
	middle->setLayout(middleLay);

	QWidget * down = new QWidget{};
	down->setLayout(downLay);

	QWidget * button = new QWidget{};
	button->setLayout(buttonLay);

	mainLay->addWidget(button);
	mainLay->addWidget(up);
	mainLay->addWidget(middle);
	mainLay->addWidget(down);
	
	this->setSignals();


}

void myClass::repoInit()
{   
	this->repoList->clear();
	
	for(auto s : ctrl->getAll_repo()){
		QString itemInList = QString::fromStdString(s.get_color() + " - " + std::to_string(s.get_size()));
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		
		this->repoList->addItem(item3);
	}

}

void myClass::setSignals() 
{
	QObject::connect(b1, SIGNAL(clicked()), this, SLOT(repoInit()));
	QObject::connect(b2, SIGNAL(clicked()), this, SLOT(sortting()));
	
}

void myClass::sortting() {

	this->repoList->clear();
	std::vector<std::string> vec;
	for (auto s : ctrl->getAll_repo()) {
		std::string x;
		x = s.get_color();
		x += " - " + std::to_string(s.get_size());

		vec.push_back(x);

	}

	sort(vec.begin(), vec.end());

	for (auto s : vec) {
		QString itemInList = QString::fromStdString(s);
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);

		this->repoList->addItem(item3);
	}

}

