#include "binary2.h"

Binary2::Binary2() {}
Binary2::~Binary2() {}


string const Binary2::getBinary(const string hexString) {
	int tmp;
	stringstream base16;

	base16 << hex << hexString;
	base16 >> tmp;
	bitset<32> binary(tmp);

	binaryString = binary.to_string();
	setLowestHighestAddress();
	
	cout << binaryString.substr(0,4)<<" "<< binaryString.substr(4,4)<<" "<<binaryString.substr(8,4)<<" "<< binaryString.substr(12,4)<<" "<< 
	binaryString.substr(16,4)<<" "<< binaryString.substr(20,4)<<" "<<binaryString.substr(24,4)<<" "<< binaryString.substr(28,4)<<endl;
	
	return binaryString;
}

void Binary2::setLowestHighestAddress(){
	lowestHexAddress = binaryString.substr(0,16);
	highestHexAddress = binaryString.substr(16,16);
}

string const Binary2::getLowestAddress(){
	return  lowestHexAddress;
}
string const Binary2::getHighestAddress(){
	return highestHexAddress;
}