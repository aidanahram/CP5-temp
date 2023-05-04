#include "Scheduler.h"
#include "utils.cpp"
#include <fstream>
#include <iostream>
#include <unordered_map>

Scheduler::Scheduler(){}

void Scheduler::readfile(std::string inputFile){
	string currentLine;
	ifstream fileReader(inputFile);

	std::unordered_map<string, int> semesterCounter;
	if (fileReader.is_open()) {
		while (fileReader) {
			getline(fileReader, currentLine); 
			if(courses.find(currentLine) == courses.end()){
				courses.insert(currentLine);
			} else {
				throw "Duplicate Course Found";
			}
			vector<string> splitLine = splitString(currentLine, ' ');
			semesterCounter[splitLine[1]]++;
			if(semesterCounter[splitLine[1]] > 3){
				throw "More than three courses in a single semester";
			}
		}
	}
}

void Scheduler::printCourses(){
	unordered_set<string>::iterator itr;
    for (itr = courses.begin(); itr != courses.end(); itr++){
        cout << (*itr) << endl;
	}
}
