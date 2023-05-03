#include "ClassNode.h"


ClassNode::ClassNode() {
	courseName = "Unnamed";
	semester = "Unknown";
	year = 9999;
}

ClassNode::ClassNode(std::string courseName) { //Might be able to simplify contstructors by having "Unnamed" as default argument for courseName
	courseName = courseName;
	semester = "Unknown";
	year = 9999;
}

/*ClassNode::~ClassNode(){
}*/

ClassNode::ClassNode(std::string courseName, std::string semester, int year) {
	courseName = courseName;
	semester = semester;
	year = year;
}

std::string ClassNode::toString() {
	return courseName + " " + std::to_string(year) + semester;
}

void ClassNode::printPreReqs() {
	std::cout << courseName << ": ";
	for (unsigned int i = 0; i < preReqs.size(); i++) {
		std::cout << courseName << " ";
	}

	std::cout << std::endl;
}


