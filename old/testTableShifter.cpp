#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdio.h>

#include <sstream>
#include <bitset>

using namespace std;


int main(){
	
	char* ptr;
	string s = "1100010000000101";
	//char* str = s;
	long parsed = strtol(s.c_str(), &ptr, 2);
	cout << s << endl;
	parsed &= ~(1 << 15);

	bitset<16> n(parsed);
	cout << n.to_string() << endl;
	parsed = (parsed >> 13);
	ostringstream resultStrin;

	resultStrin << parsed;

	string str ;
	str =  resultStrin.str();
	cout << "|" << str <<endl;
	bitset<16> x(parsed);
	cout << x.to_string() << endl;
	//parsed = (parsed & 11111);
	
	cout << parsed << endl;




	string hexString = "8255C827";

	unsigned int tmp;
	stringstream base16;

	cout << hexString << endl;

	base16 << hex << hexString;

	base16 >> tmp;
	bitset<32> binary(tmp);

	cout <<  binary.to_string() << endl;
  	

	return 0;


}
