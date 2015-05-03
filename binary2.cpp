#include "binary2.h"

Binary2::Binary2() {}
Binary2::~Binary2() {}

string const Binary2::getHexToBinary(const string hexString) {
	string binString = "";
	int tmp;
	stringstream base16;

	base16 << hex << hexString;
	base16 >> tmp;
	bitset<32> binary(tmp);

	binString = binary.to_string();
	
	return binString;
}

void Binary2::setWords(const string binString){
	lowestHexAddress = binString.substr(0,16);
	highestHexAddress = binString.substr(16,16);
}

string const Binary2::getWord0(){
	return  lowestHexAddress;
}
string const Binary2::getWord1(){
	return highestHexAddress;
}
