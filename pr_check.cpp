#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "ClassNode.h"
#include "utils.cpp" //temp

using namespace std;

void addToMap(vector<string> courseLine, unordered_map<string, ClassNode*> &currentMap) { //Takes a string of course names; if not in map, adds each to map
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
		while (preReqs) {
			getline(preReqs, currentLine); 
			if(currentLine.empty()){
				break;
			}
			vector<string> courses = splitString(currentLine, ' ');
			addToMap(courses, courseMap);
			
			if (courses.size() == 2) { //If only 1 prerequisite, add it to the first course in the line
				courseMap.at(courses.at(0))->preReqs.push_back(courseMap.at(courses.at(1)));
			}
			else { //2 or more prerequisites
			}
		}	
	}
	
	return courseMap;
}
		

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Please provide an input file" << endl;
		cout << "./pr_check <prerequisites>" << endl;
		return 0;
	}
	cout << "Prerequisite file: " << argv[1] << endl;	
	
	unordered_map<string, ClassNode*> testMap = createGraph(argv[1]);
	
}


