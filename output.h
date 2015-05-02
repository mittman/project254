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
		void const printCommand(const string cycle, const int words, const int num, const string direction);
		void printWords(const string data, const int wordPos, const int num);
		void const writeCommand(const string cycle, const int words, const int num, const string direction, fstream &out);
		void writeWords(const string data, const int wordPos, const int num, fstream &out);
};

#endif
