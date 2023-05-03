#include <vector>
#include <string>

using namespace std;

vector<string> splitString(string inputString, char delimeter){
	vector<string> result;
	int startIndex = 0, endIndex = 0;
	for (unsigned int i = 0; i <= inputString.size(); i++) {
			
			// If we reached the end of the word or the end of the input.
			if (inputString[i] == delimeter or i == inputString.size()) {
					endIndex = i;
					string temp;
					temp.append(inputString, startIndex, endIndex - startIndex);
					result.push_back(temp);
					startIndex = endIndex + 1;
			}
	}
	return result;
}
