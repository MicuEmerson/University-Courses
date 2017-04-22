#include "controller.h"


bool Controller::cmp(Project x, Project y)
{  
	if (x.get_year() > y.get_year()) {
		return false;
	}
	else {
		if (x.get_mounth() > y.get_mounth()) {
			return false;
		}
		else {
			if (x.get_day() > y.get_day())
				return false;
			else
				return true;
		}
	}
			
	return true;
}

void Controller::sort1()
{
	
	vector <Project> myVec;
	for (auto it : this->repo.getAll())
		if (it.get_isDone() == false)
			myVec.push_back(it);

	
	sort(myVec.begin(), myVec.end(), Controller::cmp);
	for (auto it : myVec)
		it.print_project();
	
			
	
}


