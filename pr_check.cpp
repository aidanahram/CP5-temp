#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "ClassNode.h"

using namespace std;

bool addToMap(string courseName, unordered_map<string, ClassNode*> &currentMap) {
	if (currentMap.find(courseName) == currentMap.end()) {
		ClassNode *newCourse = new ClassNode(courseName);
		currentMap[courseName] = newCourse;
		return true;
	}
	else {return true;}
}

unordered_map<string, ClassNode*> createGraph(string inputFile, vector<string> &allCourses) { //Read from file to map course names to ints and assign each class its prerequisite classes
	string testString;
	unordered_map<string, ClassNode*> courseMap; //Consider mapping to ClassNode pointers instead
	ifstream preReqs(inputFile);
	if (preReqs.is_open()) {
		while (preReqs) { //This loop should call helper func to fill map. For the first course on each line, it should fill its prerequisite vector with the next courses on the line
			getline(preReqs, testString);
			addToMap(testString, courseMap);
			allCourses.push_back(testString);
		}	
	}
	
	return courseMap;
}
		

int main(int argc, char *argv[]) {
	(void)argc;
	if (argv[1] == nullptr) {
		cout << "Please provide an input file" << endl;
		return 0;
	}
	cout << "Using file: " << argv[1] << endl;	
	
	vector<string> allCourses;
	
	unordered_map<string, ClassNode*> testMap = createGraph(argv[1], allCourses);

	for (unsigned int i = 0; i < allCourses.size(); i++) {
		cout << testMap.at(allCourses.at(i))->toString() << endl;
	}
}


