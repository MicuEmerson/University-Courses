#include "ui.h"

void UI::run()
{
	int cmd;
	while (1) {
		this->printMenu();
		cin >> cmd;

		switch (cmd) {
		case 1: {
			this->sb.setRoot(this->sb.add(sb.getRoot(), readBook()));
			break;
		}
		case 2: {
			Book b = readBook();
			if (this->sb.search(sb.getRoot(), b))
				this->sb.setRoot(this->sb.remove(sb.getRoot(), b));
			else
				cout << "This book is not in our library\n";

			cout << this->sb.size(this->sb.getRoot()) << endl;
			break;
		}
		case 3: {
			if (this->sb.search(sb.getRoot(), readBook()))
				cout << "This book is in our library\n";
			else
				cout << "This book is not in our library\n";
			break;
		}
		case 4: {
			cout << "Number of Books: " << this->sb.size(sb.getRoot());
			break;
		}
		case 5: {
			Iterator iter = this->sb.iterator(this->sb);
			iter.next();
			while (iter.valid()) {
				
				cout << iter.getCurrent()->printInfo();
				iter.next();
			}
			break;
		}
		case 0:
			exit(0);
			break;
		}
	}
}


Book UI::readBook()
{
	std::string a, n;

	cout << "Author: ";
	getchar();
	getline(cin, a);
	cout << "Name of the book: ";
	getline(cin, n);

	return Book(a, n);
}


void UI::printMenu()
{
	std::string s = "\t\t\Welcome to Library Software\n";
	s += "1)Add a New Book\n";
	s += "2)Remove a Book\n";
	s += "3)Search\n";
	s += "4)Get Size\n";
	s += "5)Print All Books\n";
	s += "0)Exit\n";
	cout << s << "\n";
}

void UI::readFromFile()
{
	ifstream fin("text.txt");
	std::string a, n;
	while (getline(fin,a)) {
		getline(fin, n);
		sb.setRoot(this->sb.add(sb.getRoot(), Book(a, n)));
	}
}
