#include "Table.h"

Table::Table(){}
Table::~Table(){}

string const tableLookUp(){
	string outputString;

	if (word[0])
	{
		int resultBinary = decOfData[0];
		resultBinary = (resultBinary >> 13);
		resultBinary = (resultBinary & 4);
		if (resultBinary == 0)
		{
			outputString = "Rec_Ctrl = " + resultBinary + " (no recording)";
		}
		else if (resultBinary == 2)
		{
			outputString = "Rec_Ctrl = " + resultBinary + " (no processing)";
		}
		else if (resultBinary == 3)
		{
			outputString ="Rec_Ctrl = "+ resultBinary + " (processing & recording)" + endl;
		}
		else
			outputString ="Rec_Ctrl = "+ resultBinary + " (unknown)" + endl;
	}

	if (word[1])
	{
		int resultBinary = decOfData[1];
		resultBinary = (resultBinary >> 13);
		resultBinary = (resultBinary & 8);
		if (resultBinary == 4)
		{
			outputString = "Cmd_Type = " + resultBinary + " (Type A)" + endl;
		}
		else if (resultBinary == 5)
		{
			outputString = "Cmd_Type = " + resultBinary + " (Type B)" + endl;
		}
		else if (resultBinary == 6)
		{
			outputString = "Cmd_Type = " + resultBinary + " (Type C)" + endl;
		}
		else
			outputString = "Cmd_Type = " + resultBinary + " (unknown)" + endl;
	}

	if (word[4])
	{
		int resultBinary = decOfData[4];
		resultBinary = resultBinary & 2;
		if (resultBinary == 0)
		{
			outputString = "Rec_Raw = " + resultBinary + " (disabled)" + endl;
		}
		else if (resultBinary == 1)
			outputString ="Rec_Raw = " + resultBinary + " (enabled)" + endl;
		else 
			outputString = "Rec_Raw = " + resultBinary + " (unknown)" + endl;
	}

	if (word[5])
	{
		int resultBinary = decOfData[5];
		resultBinary = resultBinary & 128;
		outputString =  "Cmd_ID =" + resultBinary + endl;
	}

	if (word[10])
	{
		int resultBinary = decOfData[10];
		resultBinary = (resultBinary >> 11);
		resultBinary = resultBinary & 32);
		outputString = "Num_Responses = " + resultBinary;
	}

	if (word[15])
	{
		int resultBinary = decOfData[15];
		resultBinary = (resultBinary >> 2);
		resultBinary = (resultBinary & 2);
		if (resultBinary == 0)
			outputString = "Reset_Enable = " + resultBinary + " (disabled)" + endl;
		else if (resultBinary == 1)
			outputString = "Reset_Enable = " + resultBinary + " (enabled)" + endl;
		else
			outputString = "Reset_Enable = " + resultBinary + " (unknown)" + endl;
	}

	if (word[22])
	{
		int resultBinary = decOfData[22];
		resultBinary = (resultBinary >> 3);
		resultBinary = (resultBinary & 2);
		if (resultBinary == 0)
			outputString =  "Direction = " + resultBinary + " (Right)" + endl;
		else if (resultBinary == 1)
			outputString =  "Direction = " + resultBinary + " (Left)" + endl;
		else
			outputString =  "Direction = " + resultBinary + " (unknown)" + endl;
	}

	if (word[32])
	{
		int resultBinary = decOfData[32];
		resultBinary = resultBinary & 32768);
		outputString =  "Num_Samples = " + resultBinary + " (Number of samples)" + endl;
	}

	if (word[37])
	{
		int resultBinary = decOfData[37];
		resultBinary = (resultBinary >> 15);
		resultBinary = (resultBinary & 2);

		if (resultBinary == 0)
			outputString =  "Parity = " + resultBinary + " (even)" + endl;
		else if (resultBinary == 1)
			outputString =  "Parity = " + resultBinary + " (odd)" + endl;
		else
			outputString =  "Parity = " + resultBinary + " (unknown)" + endl;
	}

	if (word[38])
	{
		int resultBinary = decOfData[38];
		resultBinary = (resultBinary >> 14);
		resultBinary = (resultBinary & 2);
		if (resultBinary == 0)
			outputString =  "Test = " + resultBinary + " (disabled)" + endl;
		else if (resultBinary == 1)
			outputString =  "Test = " + resultBinary + " (enabled)" + endl;
		else
			outputString =  "Test = " + resultBinary + " (unknown)" + endl;
	}

	if (word[40])
	{
		int resultBinary = decOfData[40];
		resultBinary = (resultBinary >> 7);
		resultBinary = (resultBinary & 2);
		if (resultBinary == 0)
			outputString =  "Ctrl_Enable = " + resultBinary + " (disabled)" + endl;
		else if (resultBinary == 1)
			outputString =  "Ctrl_Enable = " + resultBinary + " (enabled)" + endl;
		else
			outputString =  "Ctrl_Enable = " + resultBinary + " (unknown)" + endl;
	}

	if (word[41])
	{
		int resultBinary = decOfData[41];
		resultBinary = (resultBinary >> 8);
		resultBinary = resultBinary & 128;
		outputString =  "Code = " + resultBinary + " (Code value)" + endl;
	}


}