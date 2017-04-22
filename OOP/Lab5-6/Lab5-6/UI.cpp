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
	cout << "\t 5 - Instances" << endl;
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
	Coat *v = this->ctrl.getAll_repo();
	int n = this->ctrl.getSize_repo();
	DynamicVector <Coat> vec;
	this->ctrl.print_repo();
	cout << endl;
	
	for (int i = 0; i < n; i++)
		if (v[i].get_size() == size)
			vec.add(v[i]);

	int m = vec.getSize();
	Coat *v2 = vec.getAll();
	this->ctrl.del_repo(v2[0]);
	this->ctrl.print_repo();
	for (int i = 0; i < m; i++) {

		v2[i].print_coat();

	}
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
				else if (cmd == 5) {
					cout << "all instance: " << Coat::get_nr_instance() << "current instance: " << Coat::get_current_instance() << endl;
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



