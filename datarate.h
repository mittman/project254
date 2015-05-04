#ifndef DATARATE_H
#define DATARATE_H

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

class DataRate {

	public:
		DataRate();
		~DataRate();
		float const MegaBits(int bits, long nanoSec);
		string const GigaOrTera(float megabits);
};

#endif
