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
	

	photoButton = new QPushButton{ "See Photo" };
	insertButton = new QPushButton{"Insert"};

	//up middle buttons vertical lay
	QVBoxLayout * upButtons = new QVBoxLayout{};
	upButtons->addWidget(insertButton);
	upButtons->addWidget(photoButton);
	QWidget * upB = new QWidget{};
	upB->setLayout(upButtons);

	shopList = new QListWidget{};

	upLay->addWidget(repoList);
	upLay->addWidget(upB);
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
	seeBagButton = new QPushButton{ "ShopBag Content" };

	downLay->addWidget(addButton);
	downLay->addWidget(deleteButton);
	downLay->addWidget(updateButton);
	downLay->addWidget(filterButton);
	downLay->addWidget(seeBagButton);


	//butoane radio de sus
	QHBoxLayout * buttonLay = new QHBoxLayout{};
	b1 = new QRadioButton{ "Suffle" }; 
	b2 = new QRadioButton{ "Sorted" };
	priceBag = new QLineEdit{};

	buttonLay->addWidget(b1);
	buttonLay->addSpacing(300);
	buttonLay->addWidget(b2);
	buttonLay->addSpacing(500);
	buttonLay->addWidget(priceBag);




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

void myClass::bagInit()
{
	this->shopList->clear();
	int price = 0;

	for (auto s : ctrl->getAll_bag()) {

		price += s.get_price();
		QString itemInList = QString::fromStdString(s.get_color() + " - " + std::to_string(s.get_size()) );
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->shopList->addItem(item3);
	}
	this->priceBag->setText(QString::fromStdString(std::to_string(price) + "$"));
}

void myClass::repoInit()
{   
	this->repoList->clear();
	
	for(auto s : ctrl->getAll_repo()){

		QString itemInList = QString::fromStdString(s.get_color() + " - " + std::to_string(s.get_size()) + " - "  + std::to_string(s.get_quantity()));
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->repoList->addItem(item3);
	}

}

void myClass::setSignals() 
{
	QObject::connect(this->b1, SIGNAL(clicked()), this, SLOT(repoInit()));
	QObject::connect(this->b2, SIGNAL(clicked()), this, SLOT(sortting()));
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewCoat()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteCoat()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateCoat()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filter()));
	QObject::connect(this->insertButton, SIGNAL(clicked()), this, SLOT(addToBag()));
	QObject::connect(this->photoButton, SIGNAL(clicked()), this, SLOT(seePhoto()));
	QObject::connect(this->seeBagButton, SIGNAL(clicked()), this, SLOT(seeBagContent()));

}

void myClass::setSignalsFilter()
{
	QObject::connect(this->filterOk, SIGNAL(clicked()), this, SLOT(filterSize()));
}

void myClass::addNewCoat()
{
	std::string Size = this->sizeCoat->text().toStdString();
	std::string Color = this->colorCoat->text().toStdString();
	std::string Quantity = this->quantityCoat->text().toStdString();
	std::string Price = this->priceCoat->text().toStdString();
	std::string Link = this->linkCoat->text().toStdString();

	try
	{
		Coat x(std::stoi(Size), Color, std::stoi(Price), std::stoi(Quantity), Link);
		this->ctrl->add_repo(x);
		this->repoInit();
	}
	catch (CoatExceptions& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (DuplicateSongException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "This element is already in repo");
	}
}



int myClass::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->sizeCoat->clear();
		this->colorCoat->clear();
		this->priceCoat->clear();
		this->quantityCoat->clear();
		this->linkCoat->clear();
		return -1;
	}
	
	int idx = index.at(0).row();
	return idx;
}

void myClass::addToBag()
{
	int index = this->getRepoListSelectedIndex();
	if (index == -1) return;
	Coat x =  this->ctrl->getAll_repo()[index];

	int q = x.get_quantity() - 1;

	Coat y{ x.get_size(), x.get_color(), x.get_price(), q, x.get_photo() };

	if (x.get_quantity() == 1)
		this->ctrl->del_repo(x);
	else
		this->ctrl->update_repo(x, y);

	this->ctrl->add_bag(x);
	this->repoInit();
	this->bagInit();

}

void myClass::seePhoto()
{
	int index = this->getRepoListSelectedIndex();
	this->ctrl->getAll_repo()[index].see_photo();
}

void myClass::seeBagContent()
{
	this->ctrl->openThings_ctrl();
}

void myClass::deleteCoat()
{   
	std::string Size = this->sizeCoat->text().toStdString();
	std::string Color = this->colorCoat->text().toStdString();
	Coat x(stoi(Size), Color, 1, 1, "1");
	this->ctrl->del_repo(x);
	repoInit();
	
}

void myClass::updateCoat()
{ 
	std::string Size = this->sizeCoat->text().toStdString();
	std::string Color = this->colorCoat->text().toStdString();
	std::string Quantity = this->quantityCoat->text().toStdString();
	std::string Price = this->priceCoat->text().toStdString();
	std::string Link = this->linkCoat->text().toStdString();

	Coat x(std::stoi(Size), Color, std::stoi(Price), std::stoi(Quantity), Link);
	this->ctrl->update_repo(x, x);
	repoInit();
}



void myClass::filter()
{
	wid = new QWidget{};
	QFormLayout *box = new QFormLayout{};
	sizeFilter = new QLineEdit{};
	
	filterOk = new QPushButton{ "Ok" };
	
	box->addRow("Size: ", sizeFilter);
	box->addWidget(this->filterOk);

	wid->setLayout(box);
	wid->show();
	this->setSignalsFilter();

}

void myClass::filterSize()
{  	
	int sss = stoi(sizeFilter->text().toStdString());
	this->repoList->clear();

	for (auto s : ctrl->getAll_repo()) 
		if (s.get_size() == sss || sss == 0) {
			QString itemInList = QString::fromStdString(s.get_color() + " - " + std::to_string(s.get_size()) + " - " + std::to_string(s.get_quantity()));
			QListWidgetItem *item3 = new QListWidgetItem(itemInList);
			this->repoList->addItem(item3);
		}
	
	this->wid->close();
}

void myClass::sortting() {

	this->repoList->clear();
	std::vector<std::string> vec;

	for (auto s : ctrl->getAll_repo()) {
		std::string x;
		x = s.get_color();
		x += " - " + std::to_string(s.get_size());
		x += " - " + std::to_string(s.get_quantity());
		vec.push_back(x);
	}

	sort(vec.begin(), vec.end());

	for (auto s : vec) {
		QString itemInList = QString::fromStdString(s);
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->repoList->addItem(item3);
	}
}

