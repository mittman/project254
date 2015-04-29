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
		string const getBinary(const string hexString);
		void setLowestHighestAddress();
		string const getLowestAddress();
		string const getHighestAddress();

	private:
		string binaryString;
		string lowestHexAddress;
		string highestHexAddress;
};

#endif
