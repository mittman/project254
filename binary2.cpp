#include "binary2.h"

Binary2::Binary2() {}
Binary2::~Binary2() {}

void Binary2::hexToBinary(const string hexString) {
	int tmp;
	stringstream base16;
	//cout << hexString.substr(0,4) << "       " << hexString.substr(4,4) << endl;


	base16 << hex << hexString;
	base16 >> tmp;
	bitset<32> binary(tmp);

	binaryString = binary.to_string();
	setLowestHighestAddress();
	
	//cout << binaryString.substr(0,4)<<" "<< binaryString.substr(4,4)<<" "<<binaryString.substr(8,4)<<" "<< binaryString.substr(12,4)<<"    "<< 
	//binaryString.substr(16,4)<<" "<< binaryString.substr(20,4)<<" "<<binaryString.substr(24,4)<<" "<< binaryString.substr(28,4)<<endl;
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