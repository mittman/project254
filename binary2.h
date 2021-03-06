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
		void hexToBinary(const string hexString);
		void setLowestHighestAddress();
		string const getBinaryString();
		string const getWord0();
		string const getWord1();

	private:
		string binaryString;
		string lowestHexAddress;
		string highestHexAddress;
};

#endif
