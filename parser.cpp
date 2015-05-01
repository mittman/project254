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
#include <bitset>

#include "address.h"
#include "binary.h"
#include "binary2.h"
#include "cycle.h"
#include "output.h"

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
		
		int num = 1;
		string line = "";

		string cycle = "";
		int words = 0;
		int count = 0;
		bool marker1 = false;
		bool marker2 = false;
		unsigned long address;

		string binary = "";


		// Initialize objects
		Address a;
		Binary2 b;
		Cycle c;
		Output o;

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
				words = a.getLength(column[7]);
				count = words;
				cycle = c.getIO(column[9]);
				o.printCommand(cycle, words, num, "S-to-D");
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
				words = a.getLength(column[7]);
				count = words;
				cycle = c.getIO(column[9]);
				o.printCommand(cycle, words, num, "D-to-S");
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
				address = a.getAddress(column[6]);
				if(static_cast<long>(0x40000818) <= address && address <= static_cast<long>(0x40000C14)) {
					binary = b.getHexToBinary(column[7]);
					cout << b.getWord0() << " " << b.getWord1() <<endl;
					o.printWords(column[7], count, words, num);
					words -= 2;
				}
			}
			// D-to-S range
			else if(marker2 && words > 0) {
				address = a.getAddress(column[6]);
				if(static_cast<long>(0x40000C20) <= address && address <= static_cast<long>(0x40000C20)) {
					binary = b.getHexToBinary(column[7]);
					cout << b.getWord0() << " " << b.getWord1() <<endl;
					o.printWords(column[7], count, words, num);
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
