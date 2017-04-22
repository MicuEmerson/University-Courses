#include "UI.h"


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


void UI::printIterate(int x)
{
	cout << "\t\t1)Buy\n";
	if(x) cout << "\t\t2)See Photo\n";
	cout << "\t\t3)Next\n";
	cout << "\t\t0)Back\n";
}

int UI::getNext(vector<Coat>& vec, int pos, int size) {

	int steps = 0;
	while (true) {

		steps++;
		if (steps > vec.size())
			return -1;
		
		if (pos >= vec.size())
			pos = 0;

		if (vec[pos].get_size() == size || size == 0)
			return pos;
	    
		pos++;
	}

}




void UI::iterate(int size)
{
	vector<Coat>& vec = this->ctrl.getAll_repo();
	int pos = 0, cmd;

	while (true) {

		pos = this->getNext(vec, pos, size);

		if (pos == -1) {
			cout << "No more elements with this size in repository\n";
			break;
		}

		vec[pos].print_coat();
		this->printIterate(1);
		cin >> cmd;
		if (cmd == 1) {
			vec[pos].set_quantity(vec[pos].get_quantity() - 1);
			this->ctrl.add_bag(vec[pos]);

			if (vec[pos].get_quantity() == 0) 
				this->ctrl.del_repo(vec[pos]);
			else
				pos++;
		}
		else if (cmd == 2) {
			vec[pos].see_photo();
		}
		else if (cmd == 3) {
			pos++;
		}
		else
			break;
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



