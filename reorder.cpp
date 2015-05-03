#include "reorder.h"

Reorder::Reorder() { dbSize = 0; }
Reorder::~Reorder() {}

int const Reorder::getSize() {
	return dbSize;
}

void Reorder::popData() {
	container dataArray;
	dataArray = database.back();
	address = dataArray.address;
	binary = dataArray.binary;
	num = dataArray.num;
	database.pop_back();
}

unsigned long const Reorder::getAddress() {
	return address;
}

string const Reorder::getBinary() {
	return binary;
}

int const Reorder::getNum() {
	return num;
}

void Reorder::clearData() {
	database.clear();
	dbSize = 0;
	address = 0;
	binary = "";
	num = 0;
}

void Reorder::sortData() {
	sort(database.begin(), database.end());
}

void const Reorder::stashData(unsigned long address, const string binary, const int num) {
	container dataArray;
	dataArray.address = address;
	dataArray.binary = binary;
	dataArray.num = num;
	database.push_back(dataArray);
	++dbSize;
}
