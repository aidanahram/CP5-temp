#ifndef CLASSNODE_H
#define CLASSNODE_H

#include <string>
#include <vector>
#include <iostream>

class ClassNode{
	public:
		ClassNode();
		//~ClassNode(); Empty destructor causing compiler issues
		//ClassNode(std::string semester, int year, int courseNumber);
		ClassNode(std::string courseName, std::string semester, int year);
		
		//ClassNode* next;
		
		std::string toString();
		void printPreReqs();

	private:
		std::string courseName;
		std::string semester;
		int year;
		
		std::vector<ClassNode *> preReqs;
		
		//int courseNumber;
};

#endif
