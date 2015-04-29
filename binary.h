#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Binary {

	public:
		void displayBinary(int number); // Display the binary
		unsigned int shiftBinary(int n, int numOfShift, unsigned int bitMask); //Shifts the bit
		string binaryCode(unsigned int a, int word); //Shows the description provided
		unsigned int bitSwap(unsigned int n); // swaps the bit for high to low
	private:
		int lineNumber;
		int numWords;
};

#endif
