#include <iostream>
#include <string>
#include <math>
using namespace std;

class LogFile
{
private: int lineNumber;
	int Cycle;
	int numWords;
public: void displayBinary(int number); // Display the binary
	unsigned int shiftBinary(int n, int numOfShift, unsigned int bitMask); //Shifts the bit
	string binaryCode(unsigned int a, int word); //Shows the description provided
	unsigned int bitSwap(unsigned int n); // swaps the bit for high to low
	int CycleType(string cycle); // Determines type of cycle
}	
