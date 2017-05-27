#include "repository.h"

void Repository::add(Coat x)
{   
	if (this->find(x) != -1) 
		throw DuplicateSongException();
	
	this->v.push_back(x);
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

	v.erase(v.begin() + pos);
	
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

std::vector<Coat>& Repository::getAll()
{
	return this->v;
}

void Repository::readFromFile()
{
	std::ifstream fin("textRepo.txt");
	
	Coat x;

	while (fin >> x)
		v.push_back(x);
	
	fin.close();
}

void Repository::writeToFile()
{
	std::ofstream fout("textRepo.txt");
	
	for (auto it : this->v)
		fout << it;

	fout.close();

}




