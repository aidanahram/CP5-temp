#include "ClassNode.h"

ClassNode::ClassNode(){
	courseName = "Unnamed";
	semester = "Unknown";
	year = 9999;
	//courseNumber = 999;
	//next = nullptr;
}

/*ClassNode::~ClassNode(){
}*/

ClassNode::ClassNode(std::string courseName, std::string semester, int year) {
	courseName = courseName;
	semester = semester;
	year = year;
	//courseNumber = courseNumber;
	//next = nullptr;
}

std::string ClassNode::toString(){
	//return "CS" + std::to_string(courseNumber) + " " + std::to_string(year) + semester;
	return courseName + " " + std::to_string(year) + semester;
}

void ClassNode::printPreReqs() {
	std::cout << courseName << ": ";
	for (unsigned int i = 0; i < preReqs.size(); i++) {
		std::cout << courseName << " ";
	}
	std::cout << std::endl;
}


