#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "ClassNode.h"

using namespace std;

bool addToMap(string courseName, unordered_map<string, ClassNode*> currentMap) {
	if (currentMap.find(courseName) == currentMap.end()) {
		ClassNode *newCourse = new ClassNode(courseName);
		currentMap[courseName] = newCourse;
		return true;
	}
	else {return false;};
}

unordered_map<string, ClassNode*> createGraph(string inputFile) { //Read from file to map course names to ints and assign each class its prerequisite classes
	string testString;
	unordered_map<string, ClassNode*> courseMap; //Consider mapping to ClassNode pointers instead
	ifstream preReqs(inputFile);
	while (preReqs.good()) { //This loop should call helper func to fill map. For the first course on each line, it should fill its prerequisite vector with the next courses on the line
		getline(preReqs, testString);
		addToMap(testString, courseMap);
	}
	
	return courseMap;
}
		

int main(int argc, char *argv[]) {
	if (argv[1] == nullptr) {
		cout << "Please provide an input file" << endl;
	}
	cout << "Using file: " << argv[1] << endl;	
	
	unordered_map<string, ClassNode*) testMap = createGraph(argv[1]);

	/*for (string courseName : testMap) {
		cout << testMap[courseName].toString() << endl;
	}*/
}
