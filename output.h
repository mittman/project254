#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Output {

	public:
		Output();
		~Output();
		void setMode(const string mode);
		void const writeBlank(fstream &out);
		void const writeCommand(const string cycle, const int words, const int num, const string direction, fstream &out);
		void const writeRate(const string rate, const string cycle, const string direction, fstream &f);
		void const writeWords(const string data, const int wordPos, const int num, fstream &out);
	private:
		bool stdout;
		bool logfile;
};

#endif
