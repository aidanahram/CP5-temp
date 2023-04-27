#include "ClassNode.h"

ClassNode::ClassNode(){
	semester = "Unknown";
	year = 9999;
	courseNumber = 999;
	next = nullptr;
}

ClassNode::~ClassNode(){
}

ClassNode::ClassNode(std::string semester, int year, int courseNumber){
	semester = semester;
	year = year;
	courseNumber = courseNumber;
	next = nullptr;
}

std::string ClassNode::toString(){
	return "CS" + std::to_string(courseNumber) + " " + std::to_string(year) + semester;
}




