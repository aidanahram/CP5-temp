#include <iostream>
#include "ClassNode.h"

using namespace std;

int main(){
	string semester = "Fall";
	ClassNode *myNode = new ClassNode();
	cout << myNode->toString() << endl;
	
	myNode->printPreReqs();	
}
