#ifndef CYCLE_H
#define CYCLE_H

#include <string>
#include <sstream>
using namespace std;

class Cycle {

	public:
		Cycle();
		~Cycle();
		string const getIO(const string column9);
		double toNanoSeconds(const string reltime);
		void resetElapsed(const string cycle, const string direction);
		void setElapsed(const string cycle, const double elapsed, const string direction);
		void plusType(const string cycle, const string direction);
		int getBits(const string cycle, const string direction);
		long getElapsed(const string cycle, const string direction);
	private:
		int dsReads;
		int dsWrites;
		int sdReads;
		int sdWrites;
		int errors;
		long dsrTime;
		long dswTime;
		long sdrTime;
		long sdwTime;
		long errTime;
};

#endif
