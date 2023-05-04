#include <string>
#include <iostream>
#include "Scheduler.h"

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Please provide 2 input files" << endl;
		cout << "./sch_check <prerequisites> <schedule>" << endl;
		return 0;
	}
	cout << "Prerequisite file: " << argv[1] << endl;	
	cout << "Schedule file: " << argv[2] << endl;

	Scheduler myScheduler = Scheduler();
	try{
		myScheduler.readfile(argv[2]);
	} catch (char const *error){
		cout << error << endl;
	}
	myScheduler.printCourses();
}
