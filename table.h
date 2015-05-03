#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <sstream>
//#include <unordered_map>
#include <vector>
#include <stdlib.h>

using namespace std;

class Table {

	public:
		Table();
		~Table();
		string const getCode(const int wordPos, const string binString);
};

#endif
