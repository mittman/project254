/*
* parser.cpp
* project254 - Read log file
* Copyright (C) 2015 Team 2
* All rights reserved.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int const getLength(const string column7) {
	int data;
	stringstream base16;
	base16 << hex << column7;
	base16 >> data;
	return data/2;
}

long const getAddress(const string column6) {
	unsigned long address;
	stringstream base16;
	base16 << hex << column6;
	base16 >> address;
	return (signed long)address;
}

string const getIO(const string column9) {
	if(column9 == "Wr") {
		return "Write";
	}
	else if (column9 == "Rd") {
		return "Read";
	}
	else {
		return "???";
	}
}

void printWords(const string data, int &count, const int words, const int num) {
	cout << "Line " << num << ". Word " << (count-words) << ": " << data.substr(0,4) << endl;
	cout << "Line " << num << ". Word " << (count-words+1) << ": " << data.substr(4,7) << endl;
}

void const printCommand(const string cycle, const int words, const int num, const string direction) {
	cout << "Line " << num << ". ";
	cout << cycle << " " << direction << " command: ";
	cout << words << " words" << endl;
}

int main(int argc, char* argv[]) {

	// Check parameters
	if(argc != 2) {
		cerr << "USAGE: ./parser [filename]" << endl;
	}
	else {
		// Read log file
		fstream f;
		f.open(argv[1], ios::in);
		
		int num = 1;
		string line = "";

		string cycle = "";
		int words = 0;
		int count = 0;
		bool marker1 = false;
		bool marker2 = false;
		unsigned long address;

		// Line by line
		while (getline(f, line)) {

			// Split into vector by whitespace
			istringstream linestream(line);
			vector<string> column;
			copy(istream_iterator<string>(linestream),
				 istream_iterator<string>(),
				 back_inserter(column));

			// S-to-D marker
			if(column[6] == "40000810") {
				words = getLength(column[7]);
				count = words;
				cycle = getIO(column[9]);
				printCommand(cycle, words, num, "S-to-D");
				if(words > 0) {
					marker1 = true;
				}
				else {
					marker1 = false;
					cout << endl;
				}
			}
			// D-to-S marker
			else if(column[6] == "40000C18") {
				words = getLength(column[7]);
				count = words;
				cycle = getIO(column[9]);
				printCommand(cycle, words, num, "S-to-D");
				if(words > 0) {
					marker2 = true;
				}
				else {
					marker2 = false;
					cout << endl;
				}
			}
			// S-to-D range
			else if(marker1 && words > 0) {
				address = getAddress(column[6]);
				if(static_cast<long>(0x40000818) <= address && address <= static_cast<long>(0x40000C14)) {
					printWords(column[7], count, words, num);
					words -= 2;
				}
			}
			// D-to-S range
			else if(marker2 && words > 0) {
				address = getAddress(column[6]);
				if(static_cast<long>(0x40000C20) <= address && address <= static_cast<long>(0x40000C20)) {
					printWords(column[7], count, words, num);
					words -= 2;
				}
			}
			else if(marker1 && words == 0) {
				marker1 = false;
				cout << endl;
			}
			else if(marker2 && words == 0) {
				marker2 = false;
				cout << endl;
			}

			++num;
		}

		f.close();
	}

	return 0;
}
