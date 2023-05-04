#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "ClassNode.h"
#include "utils.cpp" //temp

using namespace std;

void addToMap(vector<string> courseLine, unordered_map<string, ClassNode*> &currentMap) { //Takes a string vector of course names; if not in map, adds each to map
	for (string course : courseLine) {
		if (currentMap.find(course) == currentMap.end()) {
			ClassNode *newCourse = new ClassNode(course);
			currentMap[course] = newCourse;
		}
	}
}

unordered_map<string, ClassNode*> createGraph(string inputFile, vector<string> &courseNames) { //Read from file to map course names to ints and assign each class its prerequisite classes
	string currentLine;
	unordered_map<string, ClassNode*> courseMap;
	
	ifstream preReqs(inputFile);
	if (preReqs.is_open()) {
		while (preReqs) {
			getline(preReqs, currentLine); //Read 1 line of file
			if(currentLine.empty()){
				break;
			}
			vector<string> courses = splitString(currentLine, ' ');
			addToMap(courses, courseMap);
			for (unsigned int i = 0; i < courses.size(); i++) {
				for (unsigned int j = 0; j < courseNames.size(); j++) {
					cout << "Ran inner loop" << endl;
					if (courses.at(i) == courseNames.at(i)) {
						break;
					}
					courseNames.push_back(courses.at(i)); //Needs debugging
				}
			}

			if (courses.size() == 2) { //Only 1 prereq
				courseMap.at(courses.at(0))->preReqs.push_back(courseMap.at(courses.at(1))); //Push it into the first course's list of prereqs
			}
			else { //2 or more (optional) prerequisites
				ClassNode *dummyNode = new ClassNode();
				courseMap.at(courses.at(0))->preReqs.push_back(dummyNode); //Insert dummy node for holding multiple optional paths
				for (unsigned int i = 0; i < courses.size(); i++) {
					dummyNode->preReqs.push_back(courseMap.at(courses.at(i)));
				}
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

	vector<string> courseNames; //Used for keeping track of all courses in the map
	unordered_map<string, ClassNode*> testMap = createGraph(argv[1], courseNames);

	for (unsigned int i = 0; i < courseNames.size(); i++) {
		cout << courseNames.at(i) << endl;
	}
}