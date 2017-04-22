#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include "domain.h"
#include "repository.h"
#include "controller.h"
#include "ui.h"
#include "tests.h"
using namespace std;

int main() {

	{  
		testing();
		Project a{ "Stairs", "Flin", 15, 4, 2017, 18, false };
		Project b{ "Website", "Spital", 5, 10,2015, 100.1, true };
		Project c{ "Aplicatie", "Ubb", 2, 3,2016, 500, false };
		Project d{ "Game", "Google", 3, 15,2015, 100, false };
		Project e{ "Music", "Facebook", 12, 15,2015, 100, true };

		Repository repo;
		Controller ctrl(repo);
		ctrl.add_ctrl(a);
		ctrl.add_ctrl(b);
		ctrl.add_ctrl(c);
		ctrl.add_ctrl(d);
		ctrl.add_ctrl(e);
		UI ui(ctrl);
		ui.run();
		
		

	}
	

	 
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	system("pause");

    return 0;
}