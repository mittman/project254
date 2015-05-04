#include "datarate.h"
DataRate::DataRate() {}
DataRate::~DataRate() {}

float const DataRate::MegaBits(const int words, const long nanoSec) {
	int bits = words * 32;
	float microSec = 0;
	microSec = nanoSec / 1000;
	return bits / microSec;
}

string const DataRate::GigaOrTera(float const megabits) {
	float speed = 0;
	string unit = "";

	if(megabits >= 1000) {
		speed = megabits / 1000;
		speed = floor(speed * 100.0) / 100.0;
		unit = " Gigabits/s";
	}
	else if (megabits >= 1000000) {
		speed = megabits / 1000000;
		speed = floor(speed * 100.0) / 100.0;
		unit = " Terabits/s";
	}
	else {
		speed = megabits;
		speed = floor(speed * 100.0) / 100.0;
		unit = " Megabits/s";
	}

	ostringstream ss;
	ss << speed;
	return ss.str() + unit;
}
