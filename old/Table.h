#ifndef TABLE_H
#define TABLE_H

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Address {

	public:
		Table();
		~Table();
		string const tableLookUp();
	private:
		int size; // need to get the number of words somehow
		int wordCount;
		vector<int> word(size);
		vector<int> fedData();
		vector<int> decOfData();
		
};

#endif
