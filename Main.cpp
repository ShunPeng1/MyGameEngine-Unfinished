#include "AppWindow.h"

using namespace std;
/*
NAMING CONVENTION

variable : lower_case_seperate_by_underscore
function : likeThisFunctionName
class	 : FirstLetterUpperCase


*/


int main() {

	AppWindow app;
	
	if (app.init()) {

		//Game loop
		while (app.isRun()) {
			app.broadcast();
		}
	}
	
	return 0;
}
