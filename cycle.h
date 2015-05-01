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
		void setElapsed(const string cycle, const double elapsed, const string direction);
		double getAvg(const string cycle, const string direction);
	private:
		int dsReads;
		int dsWrites;
		int sdReads;
		int sdWrites;
		int errors;
		double dsrTime;
		double dswTime;
		double sdrTime;
		double sdwTime;
		double errTime;
};

#endif
