#ifndef CLASSNODE_H
#define CLASSNODE_H

#include <string>

class ClassNode{
	public:
		ClassNode();
		~ClassNode();
		ClassNode(std::string semester, int year, int courseNumber);
		
		ClassNode* next;
		std::string toString();

	private:
		std::string semester;
		int year;
		int courseNumber;
};

#endif
