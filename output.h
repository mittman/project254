#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <string>
using namespace std;

class Output {

	public:
		Output();
		~Output();
		void const printCommand(const string cycle, const int words, const int num, const string direction);
		void printWords(const string data, int &count, const int words, const int num);
	private:
		string cycle;
		string data;
		string direction;
		int count;
		int words;
		int num;
};

#endif
