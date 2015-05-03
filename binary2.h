#ifndef BINARY2_H
#define BINARY2_H

#include <sstream>
#include <string>
#include <bitset>
#include <iostream>

using namespace std;

class Binary2 {

	public:
		Binary2();
		~Binary2();
		string const getHexToBinary(const string hexString);
		void setWords(const string binString);
		string const getWord0();
		string const getWord1();

	private:
		string lowestHexAddress;
		string highestHexAddress;
};

#endif
