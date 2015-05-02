#include <iostream>
#include <string>
using namespace std;

float MegaBits(int bits, float sec, string NanOrMicro)
{
	float megabits = 0;
	float totalMicroSec = 0;
	// if the input is a nanosecond, we convert to microsecond
	if (NanOrMicro == "ns")
	{
		sec *= .001;
		megabits = bits / sec;
		return megabits;
	}
	else if (NanOrMicro == "us")
	{
		megabits = bits / sec;
		return megabits;
	}
	else
	{
		return 0;
	}
}
