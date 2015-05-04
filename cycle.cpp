#include "cycle.h"

Cycle::Cycle() {
	dsReads = 0;
	dsWrites = 0;
	sdReads = 0;
	sdWrites = 0;
	errors = 0;
	dsrTime = 0;
	dswTime = 0;
	sdrTime = 0;
	sdwTime = 0;
	errTime = 0;
}

Cycle::~Cycle() {}

string const Cycle::getIO(const string column9) {
	if(column9 == "Wr") {
		return "Write";
	}
	else if (column9 == "Rd") {
		return "Read";
	}
	else {
		return "???";
	}
}

double Cycle::toNanoSeconds(const string reltime) {
	string nanotime = reltime.substr(0, reltime.size() - 2);
	double elapsed = 0.0;

	stringstream ss;
	ss << nanotime;
	ss >> elapsed;

	if(reltime.substr( reltime.length() - 2 ) == "ms") {
		return elapsed * 1000 * 1000;
	}
	else if(reltime.substr( reltime.length() - 2 ) == "us") {
		return elapsed * 1000;
	}
	else if(reltime.substr( reltime.length() - 2 ) == "ns") {
		return elapsed;
	}
    else {
		return 0;
	}
}

void Cycle::resetElapsed(const string cycle, const string direction) {
	if(direction == "D-to-S" && cycle == "Read") {
		dsrTime = 0;
	}
	else if(direction == "D-to-S" && cycle == "Write") {
		dswTime = 0;
	}
	else if(direction == "S-to-D" && cycle == "Read") {
		sdrTime = 0;
	}
	else if(direction == "S-to-D" && cycle == "Write") {
		sdwTime = 0;
	}
	else {
		errTime = 0;
	}
}

void Cycle::setElapsed(const string cycle, const double elapsed, const string direction) {
	if(direction == "D-to-S" && cycle == "Read") {
		dsrTime += elapsed;
	}
	else if(direction == "D-to-S" && cycle == "Write") {
		dswTime += elapsed;
	}
	else if(direction == "S-to-D" && cycle == "Read") {
		sdrTime += elapsed;
	}
	else if(direction == "S-to-D" && cycle == "Write") {
		sdwTime += elapsed;
	}
	else {
		errTime += elapsed;
	}
}

void Cycle::plusType(const string cycle, const string direction) {
	if(direction == "D-to-S" && cycle == "Read") {
		++dsReads;
	}
	else if(direction == "D-to-S" && cycle == "Write") {
		++dsWrites;
	}
	else if(direction == "S-to-D" && cycle == "Read") {
		++sdReads;
	}
	else if(direction == "S-to-D" && cycle == "Write") {
		++sdWrites;
	}
	else {
		++errors;
	}
}

int Cycle::getBits(const string cycle, const string direction) {
	if(direction == "D-to-S" && cycle == "Read") {
		return dsReads * 32;
	}
	else if(direction == "D-to-S" && cycle == "Write") {
		return dsWrites * 32;
	}
	else if(direction == "S-to-D" && cycle == "Read") {
		return sdReads * 32;
	}
	else if(direction == "S-to-D" && cycle == "Write") {
		return sdWrites * 32;
	}
	else {
		return errors * 32;
	}
}

long Cycle::getElapsed(const string cycle, const string direction) {
	if(direction == "D-to-S" && cycle == "Read") {
		return dsrTime;
	}
	else if(direction == "D-to-S" && cycle == "Write") {
		return dswTime;
	}
	else if(direction == "S-to-D" && cycle == "Read") {
		return sdrTime;
	}
	else if(direction == "S-to-D" && cycle == "Write") {
		return sdwTime;
	}
	else {
		return errTime;
	}
}
