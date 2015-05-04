#include "output.h"
Output::Output() {}
Output::~Output() {}

void Output::setMode(const string mode) {
	stdout = false;
	logfile = false;

	if(mode == "print") {
		stdout = true;
	}
	else if(mode == "file") {
		logfile = true;
	}
}

void const Output::writeBlank(fstream &f) {
	if(stdout) {
		cout << endl;
	}

	if(logfile) {
		f << endl;
	}
}

void const Output::writeCommand(const string cycle, const int words, const int num, const string direction, fstream &f) {
	if(stdout) {
		cout << "Line " << num << ": ";
		cout << cycle << " " << direction << " command: ";
		cout << words << " words" << endl;
	}

	if(logfile) {
		f << "Line " << num << ": ";
		f << cycle << " " << direction << " command: ";
		f << words << " words" << endl;
	}
}

void const Output::writeRate(const string rate, const string cycle, const string direction, fstream &f) {
	if(stdout) {
		cout << cycle << " " << direction << ": " << rate << endl;
	}

	if(logfile) {
		f << cycle << " " << direction << ": " << rate << endl;
	}
}

void const Output::writeWords(const string data, const int wordPos, const int num, fstream &f) {
	if(stdout) {
		cout << "Line " << num << ": Word " << wordPos << ": " << data << endl;
	}

	if(logfile) {
		f << "Line " << num << ": Word " << wordPos << ": " << data << endl;
	}
}
