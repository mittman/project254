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
#include <string.h>
#include <vector>
#include <iterator>

#include "address.h"
#include "binary2.h"
#include "cycle.h"
#include "datarate.h"
#include "output.h"
#include "reorder.h"
#include "table.h"

using namespace std;

int main(int argc, char* argv[]) {

	// Check parameters
	if(argc != 2 && argc !=3) {
		cerr << "USAGE: ./parser [filename]" << endl;
		cerr << "USAGE: ./parser [filename] [output]" << endl;
	}
	else {
		// Read log file
		fstream f;
		f.open(argv[1], ios::in);

		int num = 1;
		string line = "";

		string cycle = "";
		string direction = "";
		int words = 0;
		int count = 0;
		int wordPos = 0;
		bool marker1 = false;
		bool marker2 = false;
		unsigned long address = 0;
		long elapsed = 0;

		string binary = "";
		string highWord = "";
		string lowWord = "";
		int linenum = 0;

		// Initialize objects
		Address a;
		Binary2 b;
		Cycle c;
		Output o;
		Reorder r;
		Table t;

		// Write parsed file
		fstream output;
		if(argc == 3 && strcmp(argv[2], "-") == 0) {
			o.setMode("print");
		}
		else if(argc == 3) {
			output.open(argv[2], ios:: out);
			o.setMode("file");
		}
		else {
			output.open("log_parsed.txt", ios:: out);
			o.setMode("file");
		}

		// Line by line
		while (getline(f, line)) {

			// Split into vector by whitespace
			istringstream linestream(line);
			vector<string> column;
			copy(istream_iterator<string>(linestream),
				 istream_iterator<string>(),
				 back_inserter(column));

			c.setElapsed(cycle, elapsed, direction);
			cycle = "";
			direction = "";
			elapsed = 0;

			// S-to-D marker
			if(column[6] == "40000810") {
				words = a.getLength(column[7]);
				count = words;
				cycle = c.getIO(column[9]);
				direction = "S-to-D";
				o.writeCommand(cycle, words, num, direction, output);
				if(words > 0) {
					marker1 = true;
				}
				else {
					marker1 = false;
					r.sortData();
					for(int i = 0; i < r.getSize(); ++i) {
						r.popData();
						binary = r.getBinary();
						cycle = r.getCycle();
						elapsed = r.getElapsed();
						linenum = r.getNum();
						b.setWords(binary);

						wordPos = (count-words);
						highWord = t.getCode(wordPos, b.getWord0());
						if(highWord != "") {
							o.writeWords(highWord, wordPos, linenum, output);
						}

						wordPos = (count-words+1);
						lowWord = t.getCode(wordPos, b.getWord1());
						if(lowWord != "") {
							o.writeWords(lowWord, wordPos, linenum, output);
						}

						words -= 2;
					}
					r.clearData();

					o.writeBlank(output);
				}
			}
			// D-to-S marker
			else if(column[6] == "40000C18") {
				words = a.getLength(column[7]);
				count = words;
				cycle = c.getIO(column[9]);
				direction = "D-to-S";
				o.writeCommand(cycle, words, num, direction, output);
				if(words > 0) {
					marker2 = true;
				}
				else {
					marker2 = false;
					r.sortData();
					for(int i = 0; i < r.getSize(); ++i) {
						r.popData();
						binary = r.getBinary();
						cycle = r.getCycle();
						elapsed = r.getElapsed();
						linenum = r.getNum();
						b.setWords(binary);

						wordPos = (count-words);
						highWord = t.getCode(wordPos, b.getWord0());
						if(highWord != "") {
							o.writeWords(highWord, wordPos, linenum, output);
						}

						wordPos = (count-words+1);
						lowWord = t.getCode(wordPos, b.getWord1());
						if(lowWord != "") {
							o.writeWords(lowWord, wordPos, linenum, output);
						}

						words -= 2;
					}
					r.clearData();

					o.writeBlank(output);
				}
			}
			// S-to-D range
			else if(marker1 && words > 0) {
				address = a.getAddress(column[6]);
				if(static_cast<long>(0x40000818) <= address && address <= static_cast<long>(0x40000C14)) {
					binary = b.getHexToBinary(column[7]);
					cycle = c.getIO(column[9]);
					direction = "S-to-D";
					elapsed = c.toNanoSeconds(column[2]);
					r.stashData(address, binary, cycle, elapsed, num);
					c.plusType(cycle, direction);
				}
			}
			// D-to-S range
			else if(marker2 && words > 0) {
				address = a.getAddress(column[6]);
				if(static_cast<long>(0x40000C20) <= address && address <= static_cast<long>(0x4000101C)) {
					binary = b.getHexToBinary(column[7]);
					cycle = c.getIO(column[9]);
					direction = "D-to-S";
					elapsed = c.toNanoSeconds(column[2]);
					r.stashData(address, binary, cycle, elapsed, num);
					c.plusType(cycle, direction);
				}
			}
			else if(marker1 && words == 0) {
				marker1 = false;
				o.writeBlank(output);
			}
			else if(marker2 && words == 0) {
				marker2 = false;
				o.writeBlank(output);
			}

			++num;
		}

		f.close();

		// Data Rates
		//o.writeRate(c.getAvg("Read", "S-to-D")*1000, "Read", "S-to-D", output);
		//o.writeRate(c.getAvg("Read", "D-to-S")*1000, "Read", "D-to-S", output);
		//o.writeRate(c.getAvg("Write", "S-to-D")*1000, "Write", "S-to-D", output);
		//o.writeRate(c.getAvg("Write", "D-to-S")*1000, "Write", "D-to-S", output);

		output.close();
	}

	return 0;
}
