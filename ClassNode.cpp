#include "ClassNode.h"


ClassNode::ClassNode() {
	courseName = "Unnamed";
	courseNumber = 0;
	semester = "Unknown";
	year = 9999;
}

ClassNode::ClassNode(std::string courseName) { //Might be able to simplify contstructors by having "Unnamed" as default argument for courseName
	this->courseName = courseName;
	courseNumber = ClassNode::findNumber();
	semester = "Unknown";
	year = 9999;
}

ClassNode::ClassNode(std::string courseName, std::string semester, int year) {
	courseName = courseName;
	courseNumber = ClassNode::findNumber();
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

int ClassNode::findNumber() { //Extracts the 3 digits at the end of courseName
	if (courseName == "Unnamed") {return 0;}

	std::string numberString;
	unsigned int i;
	for (i = 0; i < courseName.length(); i++) { //Loop until first digit found
		if (isdigit(courseName[i])) {
			numberString += courseName[i];
		}
	}
	return stoi(numberString);
}