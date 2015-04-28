#include "binary.h"

void displayBinary(int number) //Display the binary
{
	int r; //remainder
	if(number <= 1)
	{
		cout << number;
		return;
	}

	r = number%2;
	displayBinary(number >> 1);
	cout << r;
}

unsigned int shiftBinary(int n, int numOfShift, unsigned int bitMask) //Shifts the bit
{
	unsigned int shift = ((n & bitMask) >> numOfShift);
	return shift;
}

unsigned int bitSwap(unsigned int n) //Swaps the for high to low
{
	n = (n & 170) >> 1 | (n & 85) << 1;
	n = (n & 204) >> 2 | (n & 51) << 2;
	n = (n & 240) >> 4 | (n & 15) << 1;
	return n;
}

string binaryCode(unsigned int a, int word) // Shows the description provided
{
	string phrase;
	if(word==0)
	{
		if(a==0)
		phrase = "no recording\n";
		else if(a==2)
		phrase = "no processing\n";
		else if(a==3)
		phrase = "processing & recording\n";
	}

	else if(word==1)
	{
		if(a==4)
		phrase = "Type A\n";
		else if(a==5)
		phrase = "Type B\n";
		else if(a==6)
		phrase = "Type C\n";
	}

	else if(word==4)
	{
		if(a==0)
		phrase = "disable\n";
		else if(a==1)
		phrase = "enabled\n";
	}

	else if(word==5)
	{
		//command id
	}

	else if(word==10)
	{
		//number of responses
	}
	
	else if(word==15)
	{
		if(a==0)
		phrase = "disabled\n";
		if(a==1)
		phrase = "enabled\n";
	}
	
	else if(word==22)
	{
		if(a==0)
		phrase = "Right\n";
		if(a==1)
		phrase = "Left\n";
	}

	else if(word=32)
	{
		//number of samples
	}

	else if(word=37)
	{
		if(a==0)
		phrase = "even\n";
		if(a==1)
		phrase = "odd\n";
	}

	else if(word=38)
	{
		if(a==0)
		phrase = "disable\n";
		if(a==1)
		phrase = "enable\n";
	}
	
	else if(word=40)
	{
		if(a==0)
		phrase = "disable\n";
		if(a==1)
		phrase = "enable\n";
	}
	
	else if(word==41)
	{
		//code value
	}

	return phrase;
}

// This function will return an integer 1 if it is a read, or an integer 2 if it is a write. My idea for the logic of using the function will be something like:if (cycle = 1) then it is a read and display "Read S-to-D command" or whatever. The 0 is just to check if string cycle was passed through properly, can be removed once we actually finalize the code.
int CycleType(string cycle)
{
	string read = "Rd";
	string write = "Wr";
	if( cycle == read )
	{
		return 1;
	}
	else if (cyle == write)
	{
		return 2;
	}
	// to check if the strings were compared properly
	else
	{
		return 0;
	}
}
