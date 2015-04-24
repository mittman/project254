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
				cout << num << ". " << column[6] << "\t" << column[7] << "\t S-to-D marker" << endl;
				++max;
			}
			// D-to-S marker
			else if(column[6] == "40000C18") {
				cout << num << ". " << column[6] << "\t" << column[7] << "\t D-to-S marker" << endl;
				++max;
			}

			++num;
		}

		f.close();
	}

	return 0;
}
