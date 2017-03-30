#include "UI.h"
#include "dynamicArr.h"

int UI::readInteger(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

void UI::readCoat(int &s, string &c, int &p, int &q, string &ph)
{
	s = readInteger("size: ");
	cout << "color: ";
	cin >> c;
	p = readInteger("price: ");
	q = readInteger("quantity: ");
	cout << "photo: ";
	cin >> ph;

}


void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode" << endl;
	cout << "2 - User mode" << endl;
	cout << "0 - Exit." << endl;
}

void UI::printAdminMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add " << endl;
	cout << "\t 2 - Update." << endl;
	cout << "\t 3 - Delete " << endl;
	cout << "\t 4 - Show All" << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printUserMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Buy some coats" << endl;
	cout << "\t 2 - Show cart list" << endl;
	cout << "\t 0 - Back." << endl;
}
void UI::iterate(int size)
{
	Coat *vec = this->ctrl.getAll_repo();
	int n = this->ctrl.getSize_repo();
	int m = 0;
	int i = 0, flag = 1, cmd;

	for (int i = 0; i < n; i++) {
		if (vec[i].get_size() == size)
			m++;
	}
	if (size == 0)
		m = n;

	while (true) {

		if (flag == 0) {
			cout << "No more items with this size\n";
			break;
		}
		flag = 0;

		if ((size == 0 || vec[i].get_size() == size) && vec[i].get_quantity()) {

			flag = 1;
			vec[i].print_coat();
			cout << "\t\t1 Buy\n";
			cout << "\t\t2 See Photo\n";
			cout << "\t\t3 Next\n";
			cout << "\t\t4 Back\n";
			cin >> cmd;

			if (cmd == 1) {
				this->ctrl.add_bag(vec[i]);
				vec[i].set_quantity(vec[i].get_quantity() - 1);
				cout << "'\t\tThe current cart value is: " << ctrl.get_price_bag() << endl;
			}
			else if (cmd == 2) {
				vec[i].see_photo();
				cout << "\t\t1 Buy\n";
				cout << "\t\t2 Next\n";
				cout << "\t\t3 Back\n";
				cin >> cmd;
				if (cmd == 1) {
					this->ctrl.add_bag(vec[i]);
					vec[i].set_quantity(vec[i].get_quantity() - 1);
					cout << "'\t\tThe current cart value is: " << ctrl.get_price_bag() << endl;
				}
				else if (cmd == 2) {
					i++;
				}
				else {
					break;
				}
			}
			else if (cmd == 3) {
				i++;
			}
			else if (cmd == 4) {
				flag = 2;
			}
			else {
				cout << "Wrong command\n";
			}
		}

		if (flag == 2)
			break;

		if (i == m)
			i = 0;

		if (vec[i].get_quantity() == 0) {
			cout << "Coat size:" << vec[i].get_size() << " and color: " << vec[i].get_color() << " out of stock! We will present you the next one!\n";
			this->ctrl.del_repo(vec[i]);
			i++;
			m--;
			if (m == 0){
				cout << "No more coats of this size\n";
				break;
			}
	    }

		if (i == m)
			i = 0;
	}
	for (int i = 0; i < n; i++)
		if (!vec[i].get_quantity())
			this->ctrl.del_repo(vec[i]);
	
}



void UI::run()
{
	int cmd = -1;
	while (true) {

		this->printMenu();
		cin >> cmd;
		if (cmd == 1) {

			int s, p, q, ss;
			string c,cc, ph;

			while (true) {
				this->printAdminMenu();
				cin >> cmd;
				if (cmd == 1) {
					
					readCoat(s, c, p, q, ph);
					Coat x(s, c, p, q, ph);
					if (!ctrl.add_repo(x))
						cout << "this elem already in repo\n";
				}
				else if (cmd == 2) {
					
					ss = readInteger("size: ");
					cout << "color: ";
					cin >> cc;
					readCoat(s, c, p, q, ph);
					Coat x(ss, cc, 0, 0, " ");
					Coat y(s, c, p, q, ph);
					
					if (!ctrl.update_repo(x, y))
						cout << "no such an elem in repo\n";

				}
				else if (cmd == 3) {
					
					s = readInteger("size: ");
					cout << "color: ";
					cin >> c;
					Coat x(s, c, 0, 0, " ");
					if(!ctrl.del_repo(x))
						cout << "no such an elem in repo\n";
				}
				else if (cmd == 4) {
					this->ctrl.print_repo();
				}
				else if (cmd == 0) {
					break;
				}
				else
					cout << "invalid command\n";
			}
		}
		else if (cmd == 2) {

			while (true) {

				printUserMenu();
				cin >> cmd;
				if (cmd == 1) {
					int size;
					cout << "what is the size of coat?\n";
					cin >> size;
					this->iterate(size);
				}
				else if (cmd == 2) {

					this->ctrl.print_bag();
					cout << endl;
				}
				else if (cmd == 0) {
					break;
				}
				else {
					cout << "invalid command\n";
				}
			}

		}
		else if (cmd == 0)
			break;
		else {
			cout << "Invalid input\n";
		}
	}
}



