#include "address.h"

Address::Address() {}
Address::~Address() {}

int const Address::getLength(const string column7) {
	int data;
	stringstream base16;
	base16 << hex << column7;
	base16 >> data;
	return data/2;
}

long const Address::getAddress(const string column6) {
	unsigned long address;
	stringstream base16;
	base16 << hex << column6;
	base16 >> address;
	return (signed long)address;
}
