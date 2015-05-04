#include <iostream>
#include <string>
using namespace std;

// From what I understand, and based off what the professor said, to convert data rates is to take the number of bits/microseconds
// this function is purely to convert to megabits
float MegaBits(int bits, float nanoSec)
{
	float megabits = 0;
	float microSec = 0;
	microSec =  nanoSec/1000;
	
	megabits = bits/microSec;
	return megabits;
}

// this is to check if it is better to represent the value as megabit, gigabit or terabit and return a string representing the data rate (MB/s, GB/s or TB/s)
string GigaOrTera(float megabits)
{
	if(megabits >= 1000)
	{
		megabits /= 1000;
		return megabits + " GB/s";
	}
	else if (megabits >= 10000)
	{	
		megabits /= 10000;
		return megabits + " TB/s";
	}
	else
	{
		return megabits + " MB/s";
	}
}
