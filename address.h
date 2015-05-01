#ifndef ADDRESS_H
#define ADDRESS_H

#include <sstream>
#include <string>
using namespace std;

class Address {

	public:
		Address();
		~Address();
		int const getLength(const string column7);
		long const getAddress(const string column6);
};

#endif
