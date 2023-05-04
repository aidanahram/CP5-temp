#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Scheduler {
	public: 
		Scheduler();
		
		void readfile(std::string inputFile);
		void printCourses();

		unordered_set<string> courses;
};

#endif
