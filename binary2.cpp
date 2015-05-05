#include "binary2.h"

Binary2::Binary2() {}
Binary2::~Binary2() {}

void Binary2::hexToBinary(const string hexString) {
	unsigned int tmp;
	stringstream base16;

	base16 << hex << hexString;
	base16 >> tmp;
	bitset<32> binary(tmp);

	binaryString = binary.to_string();
	setLowestHighestAddress();
	
}

void Binary2::setLowestHighestAddress(){
	lowestHexAddress = binaryString.substr(0,16);
	
	highestHexAddress = binaryString.substr(16,16);

}

string const Binary2::getBinaryString(){
	return binaryString;
}

string const Binary2::getWord0(){
	
	return  lowestHexAddress;
}
string const Binary2::getWord1(){
	
	return highestHexAddress;
}