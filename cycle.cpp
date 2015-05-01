#include "cycle.h"

Cycle::Cycle() {}
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
		return 0.0;
	}
}

void Cycle::setElapsed(const string cycle, const double elapsed, const string direction) {
	if(direction == "D-to-S" && cycle == "Read") {
		dsrTime += elapsed;
		++dsReads;
	}
	else if(direction == "D-to-S" && cycle == "Write") {
		dswTime += elapsed;
		++dsWrites;
	}
	else if(direction == "S-to-D" && cycle == "Read") {
		sdrTime += elapsed;
		++sdReads;
	}
	else if(direction == "S-to-D" && cycle == "Write") {
		sdwTime += elapsed;
		++sdWrites;
	}
	else {
		errTime += elapsed;
		++errors;
	}
}

double Cycle::getAvg(const string cycle, const string direction) {
	if(direction == "D-to-S" && cycle == "Read") {
		return dsrTime / dsReads;
	}
	else if(direction == "D-to-S" && cycle == "Write") {
		return dswTime / dsWrites;
	}
	else if(direction == "S-to-D" && cycle == "Read") {
		return sdrTime / sdReads;
	}
	else if(direction == "S-to-D" && cycle == "Write") {
		return sdwTime / sdWrites;
	}
	else {
		return errTime / errors;
	}
}
