#include "output.h"

Output::Output() {}
Output::~Output() {}

void const Output::printCommand(const string cycle, const int words, const int num, const string direction) {
	cout << "Line " << num << ". ";
	cout << cycle << " " << direction << " command: ";
	cout << words << " words" << endl;
}

void Output::printWords(const string data, int &count, const int words, const int num) {
	cout << "Line " << num << ". Word " << (count-words) << ": " << data.substr(0,4) << endl;
	cout << "Line " << num << ". Word " << (count-words+1) << ": " << data.substr(4,4) << endl;
}
