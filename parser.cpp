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

int main(int argc, char* argv[]) {

	// Check parameters
	if(argc != 2) {
		cerr << "USAGE: ./parser [filename]" << endl;
	}
	else {
		// Read log file
		fstream f;
		f.open(argv[1], ios::in);
		
		int max = 0;
		int num = 1;
		string line = "";

		// FIXME: segfaults without max
		while (f.good() && !f.eof() && max < 10) {
			// Line by line
			getline(f, line);

			// Split into vector by whitespace
			istringstream linestream(line);
			vector<string> column;
			copy(istream_iterator<string>(linestream),
				 istream_iterator<string>(),
				 back_inserter(column));

			// S-to-D marker
			if(column[6] == "40000810") {
				cout << column[6] << "\t" << column[7] << "\t Line " << num << ". " << "\t";
				cout << getIO(column[9]) << " S-to-D command: ";
				cout << getLength(column[7]) << " words" << endl;
				++max;
			}
			// D-to-S marker
			else if(column[6] == "40000C18") {
				cout << column[6] << "\t" << column[7] << "\t Line " << num << ". " << "\t";
				cout << getIO(column[9]) << " D-to-S command: ";
				cout << getLength(column[7]) << " words" << endl;
				++max;
			}

			++num;
		}

		f.close();
	}

	return 0;
}
