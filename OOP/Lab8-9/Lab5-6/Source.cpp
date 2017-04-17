#include <iostream>
#include <stdlib.h>
#include "domain.h"
#include "repository.h"
#include "controller.h"
#include "UI.h"
#include "testing.h"
#include <crtdbg.h>
using namespace std;

int main() {

	{
		Repository repo;
		Controller ctrl(repo);
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
