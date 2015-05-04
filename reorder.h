#ifndef REORDER_H
#define REORDER_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Reorder {

	public:
		struct container {
			unsigned long address;
			string binary;
			string cycle;
			long elapsed;
			int num;

			bool operator<(const container& a) const
			{
				return address < a.address;
			}
		};
		Reorder();
		~Reorder();
		int const getSize();
		void popData();
		unsigned long const getAddress();
		string const getBinary();
		string const getCycle();
		long const getElapsed();
		int const getNum();
		void clearData();
		void sortData();
		void const stashData(unsigned long address, const string binary, const string cycle, const long elapsed, const int num);
	private:
		vector<container> database;
		int dbSize;
		int num;
		unsigned long address;
		string binary;
		string cycle;
		long elapsed;
};

#endif
