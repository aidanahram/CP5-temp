#ifndef CLASSNODE_H
#define CLASSNODE_H

#include <string>
#include <vector>
#include <iostream>

class ClassNode{
	public:
		ClassNode();
		//~ClassNode(); Empty destructor causing compiler issues
		ClassNode(std::string courseName, std::string semester, int year);
		
		std::string toString();
		void printPreReqs();
		
		std::string courseName;
		std::string semester;
		int year;
		
		std::vector<ClassNode *> preReqs;

	private: //Easier to have them public; if keeping them private, must add getter functions later
		/*std::string courseName;
		std::string semester;
		int year;
		
		std::vector<ClassNode *> preReqs;
		
		nt courseNumber;*/
};

#endif
