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
