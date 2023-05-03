#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "ClassNode.h"
#include "utils.cpp" //temp

using namespace std;

void addToMap(vector<string> courseLine, unordered_map<string, ClassNode*> &currentMap) {
	for (string course : courseLine) {
		if (currentMap.find(course) == currentMap.end()) {
			ClassNode *newCourse = new ClassNode(course);
			currentMap[course] = newCourse;
		}
	}
}

unordered_map<string, ClassNode*> createGraph(string inputFile) { //Read from file to map course names to ints and assign each class its prerequisite classes
	string currentLine;
	unordered_map<string, ClassNode*> courseMap;
	
	ifstream preReqs(inputFile);
	if (preReqs.is_open()) {
		while (preReqs) { //This loop should call helper func to fill map. For the first course on each line, it should fill its prerequisite vector with the next courses on the line
			getline(preReqs, currentLine);
			vector<string> courses = splitString(currentLine, ' ');
			addToMap(courses, courseMap);
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
	
	unordered_map<string, ClassNode*> testMap = createGraph(argv[1]);
	
	for (auto course : testMap) {
		course.first << " " << course.second << endl;
	}
}


