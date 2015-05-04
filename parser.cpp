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
#include <algorithm>
#include <iterator>

#include "address.h"
#include "binary2.h"
#include "cycle.h"
#include "datarate.h"
#include "output.h"
#include "table.h"

using namespace std;

int main(int argc, char* argv[]) {

	// Check parameters
	if(argc != 2 && argc != 3) {
		cerr << "USAGE: ./parser [filename]" << endl;
		cerr << "USAGE: ./parser [filename] [output]" << endl;
		cerr << "USAGE: ./parser [filename] -" << endl;
	}
	else {
		// Read log file
		fstream f;
		f.open(argv[1], ios::in);

		int num = 1;
		string line = "";
		string cycle = "";
		string direction = "";
		double elapsed = 0;

		int words = 0;
		int count = 0;
		int wordPos = 0;
		bool marker1 = false;
		bool marker2 = false;
		bool printList = false;
		unsigned long address;

		vector<unsigned long> addressList;
		vector<int> wordPosList;
		vector<string> binaryList;
		vector<int> numLines;

		string highWord = "";
		string lowWord = "";
		string binary = "";

		// Initialize objects
		Address a;
		Binary2 b;
		Cycle c;
		DataRate d;
		Output o;
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

			// S-to-D marker
			if(column[6] == "40000810") {
				if(printList){
					if(addressList[0] > addressList[1]){
						reverse(wordPosList.begin(),wordPosList.end());
					}
					vector<int>::size_type sz = binaryList.size();
					for (unsigned i=0; i<sz; i++){

						highWord = t.getCode(wordPosList[i], binaryList[i]);
						if(highWord != "") {
							o.writeWords(highWord, wordPosList[i], numLines[i], output);
						}

					}

					o.writeBlank(output);
					printList = false;
					binaryList.clear();
					numLines.clear();
					wordPosList.clear();
					addressList.clear();
				}

				words = a.getLength(column[7]);
				count = words;
				cycle = c.getIO(column[9]);
				direction = "S-to-D";
				elapsed = c.toNanoSeconds(column[2]);
				c.setElapsed(cycle, elapsed, direction);
				c.plusType(cycle, direction);
				o.writeCommand(cycle, words, num, direction, output);

				if(words > 0) {
					marker1 = true;
				}
				else {
					marker1 = false;
					o.writeBlank(output);
				}
			}

			// D-to-S marker
			else if(column[6] == "40000C18") {
				if(printList){
					if(addressList[0] > addressList[1]){
						reverse(wordPosList.begin(),wordPosList.end());
					}
					vector<int>::size_type sz = binaryList.size();
					for (unsigned i=0; i<sz; i++){

						highWord = t.getCode(wordPosList[i], binaryList[i]);
						if(highWord != "") {
							o.writeWords(highWord, wordPosList[i], numLines[i], output);
						}

					}

					o.writeBlank(output);
					printList = false;
					binaryList.clear();
					numLines.clear();
					wordPosList.clear();
					addressList.clear();
				}

				words = a.getLength(column[7]);
				count = words;
				cycle = c.getIO(column[9]);
				direction = "D-to-S";
				elapsed = c.toNanoSeconds(column[2]);
				c.setElapsed(cycle, elapsed, direction);
				c.plusType(cycle, direction);
				o.writeCommand(cycle, words, num, direction, output);

				if(words > 0) {
					marker2 = true;
				}
				else {
					marker2 = false;
					o.writeBlank(output);
				}

			}
			// S-to-D range
			else if(marker1 && words > 0) {
				address = a.getAddress(column[6]);
				if(static_cast<long>(0x40000818) <= address && address <= static_cast<long>(0x40000C14)) {
					if(addressList.size() <2){
						addressList.push_back(address);
					}

					b.hexToBinary(column[7]);
					cycle = c.getIO(column[9]);
					direction = "S-to-D";
					elapsed = c.toNanoSeconds(column[2]);
					c.setElapsed(cycle, elapsed, direction);
					c.plusType(cycle, direction);

					wordPos = (count-words);
					wordPosList.push_back(wordPos);
					binaryList.push_back(b.getWord0());
					numLines.push_back(num);

					wordPos = (count-words+1);
					wordPosList.push_back(wordPos);
					binaryList.push_back(b.getWord1());
					numLines.push_back(num);

					words -= 2;
					printList = true;
				}
			}
			// D-to-S range
			else if(marker2 && words > 0) {
				address = a.getAddress(column[6]);
				if(static_cast<long>(0x40000C20) <= address && address <= static_cast<long>(0x4000101C)) {
					if(addressList.size() <2){
						addressList.push_back(address);
					}

					b.hexToBinary(column[7]);
					cycle = c.getIO(column[9]);
					direction = "D-to-S";
					elapsed = c.toNanoSeconds(column[2]);
					c.setElapsed(cycle, elapsed, direction);
					c.plusType(cycle, direction);

					wordPos = (count-words);
					wordPosList.push_back(wordPos);
					binaryList.push_back(b.getWord0());
					numLines.push_back(num);

					wordPos = (count-words+1);
					wordPosList.push_back(wordPos);
					binaryList.push_back(b.getWord1());
					numLines.push_back(num);

					words -= 2;
					printList = true;

				}
			}
			else if(marker1 && words == 0) {
				marker1 = false;
			}
			else if(marker2 && words == 0) {
				marker2 = false;
			}

			++num;
		}

		f.close();

		// Data Rates
		cycle = "Read"; direction = "S-to-D";
		o.writeRate(d.GigaOrTera(d.MegaBits(c.getBits(cycle, direction), c.getElapsed(cycle, direction))), cycle, direction, output);
		cycle = "Read"; direction = "D-to-S";
		o.writeRate(d.GigaOrTera(d.MegaBits(c.getBits(cycle, direction), c.getElapsed(cycle, direction))), cycle, direction, output);
		cycle = "Write"; direction = "S-to-D";
		o.writeRate(d.GigaOrTera(d.MegaBits(c.getBits(cycle, direction), c.getElapsed(cycle, direction))), cycle, direction, output);
		cycle = "Write"; direction = "D-to-S";
		o.writeRate(d.GigaOrTera(d.MegaBits(c.getBits(cycle, direction), c.getElapsed(cycle, direction))), cycle, direction, output);

		output.close();
	}

	return 0;
}
