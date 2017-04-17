#include "repository.h"

bool Repository::add(Coat x)
{   
	if (this->find(x) != -1)
		return false;

	this->v.push_back(x);
	return true;
}

int Repository::find(Coat x)
{   
	for (int i = 0; i < this->v.size(); i++)
		if (v[i] == x)
			return i;
	return -1;
}

bool Repository::del(Coat x)
{   
	int pos = this->find(x);
	if (pos == -1)
		return false;

	iter_swap(this->v.begin() + pos, this->v.begin() + v.size() - 1);
	v.pop_back();
	
	return true;
}

bool Repository::update(Coat x, Coat y)
{   
	if(this->find(x) == -1)
		return false;
	this->del(x);
	this->add(y);
	return true;
}

void Repository::print()
{   
	for (auto it : v)
		it.print_coat();
}

std::vector<Coat> Repository::getAll()
{
	return this->v;
}

int convert(std::string s) {

	int nr = 0;
	for (int i = 0; i < s.size(); i++)
		nr = nr * 10 + s[i] - 48;
	return nr;
}

std::string convert2(int x) {

	std::string res;
	while (x) {
		res += ((x % 10) + 48);
		x /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

void Repository::readFromFile()
{
	std::ifstream fin("repository.txt");
	std::string x;
	while (fin >> x) {
		
		std::stringstream ss(x);
		std::vector<std::string> result;

		while (ss.good()) {
			std::string sir;
			getline(ss, sir, ',');
			result.push_back(sir);
		}

		Coat x(convert(result[0]), result[1], convert(result[2]), convert(result[3]), result[4]);
		this->add(x);
	}


	fin.close();
}

static int firstTime = 1;
void Repository::writeToFile()
{  
	
	if (!firstTime)
		return;

	firstTime = 0;
	std::ofstream fout("repository.txt");
	std::string s;
	
	for (auto it : this->v) {
		s = convert2(it.get_size());
		s += "," + it.get_color();
		s += "," + convert2(it.get_price());
		s += "," + convert2(it.get_quantity());
		s += "," + it.get_photo() + "\n";
		fout << s;
	}
	fout.close();
}




