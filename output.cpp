#include "output.h"
Output::Output() {}
Output::~Output() {}

void const Output::printCommand(const string cycle, const int words, const int num, const string direction, fstream &f) {
	f << "Line " << num << ". ";
	f << cycle << " " << direction << " command: ";
	f << words << " words" << endl;
}

void Output::printWords(const string data, int &count, const int words, const int num, fstream &f) {
	f << "Line " << num << ". Word " << (count-words) << ": " << data.substr(0,4) << endl;
	f << "Line " << num << ". Word " << (count-words+1) << ": " << data.substr(4,4) << endl;
}
