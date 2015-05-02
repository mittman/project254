#include "output.h"
Output::Output() {}
Output::~Output() {}

void const Output::printCommand(const string cycle, const int words, const int num, const string direction) {
	cout << "Line " << num << ". ";
	cout << cycle << " " << direction << " command: ";
	cout << words << " words" << endl;
}

void Output::printWords(const string data, const int wordPos, const int num) {
	cout << "Line " << num << ". Word " << wordPos << ": " << data << endl;
}

void const Output::writeCommand(const string cycle, const int words, const int num, const string direction, fstream &f) {
	f << "Line " << num << ". ";
	f << cycle << " " << direction << " command: ";
	f << words << " words" << endl;
}

void Output::writeWords(const string data, const int wordPos, const int num, fstream &f) {
	f << "Line " << num << ". Word " << wordPos << ": " << data << endl;
}
