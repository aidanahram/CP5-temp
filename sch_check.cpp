#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	if (argv[1] == nullptr || argv[2] == nullptr) {
		cout << "Please provide an 2 input files" << endl;
		cout << "./sch_check <prerequisites> <schedule>" << endl;
		return 0;
	}
	cout << "Using file: " << argv[1] << endl;	
}