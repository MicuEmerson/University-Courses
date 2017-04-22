#include "ui.h"

void UI::run()
{
	int cmd, day, mounth, year;
	double cost;
	bool isDone;
	string name;
	string customer;

	while (true) {
	
		this->print_menu();
		cout << "cmd: ";
		cin >> cmd;
		if (cmd == 1) {
			cout << "Name: ";
			cin >> name;

			cout << "Customer: ";
			cin >> customer;

			cout << "Day: ";
			cin >> day;

			cout << "Mounth: ";
			cin >> mounth;

			cout << "Year: ";
			cin >> year;

			cout << "Cost: ";
			cin >> cost;

			cout << "isDone: ";
			cin >> isDone;

			Project x{ name, customer, day, mounth, year, cost, isDone };
			if (this->ctrl.add_ctrl(x) == false)
				cout << "This Project already in our system!\n";

		}
		else if (cmd == 2) {
			cout << "Name: ";
			cin >> name;

			cout << "Customer: ";
			cin >> customer;
			Project x{ name, customer, 1, 1, 1, 1, 1};
			if (this->ctrl.mark_ctrl(x) == false)
				cout << "Cannot mark this project!\n";

		}
		else if (cmd == 3) {
			this->ctrl.print_ctrl();
		}
		else if (cmd == 4) {
			this->ctrl.sort1();
		}
		else if (cmd == 5) {
			cout << this->ctrl.cost_ctrl() << endl;
		}
		else if (cmd == 0) {
			break;
		}
		else {
			cout << "Invalid Input\n";
		}
		

	}
}

void UI::print_menu()
{
	cout << "\t\tWelcome to Projects\n";
	cout << "1)Add\n";
	cout << "2)Mark\n";
	cout << "3)Show All \n";
	cout << "4)Sort \n";
	cout << "5)Total cost\n";
	cout << "0)Exit\n";
}
