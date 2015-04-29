#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<char, int> mymap;
	mymap['0'] = 0;
	mymap['1'] = 1;
	mymap['2'] = 2;
	mymap['3'] = 3;
	mymap['4'] = 4;
	mymap['5'] = 5;
	mymap['6'] = 6;
	mymap['7'] = 7;
	mymap['8'] = 8;
	mymap['9'] = 9;
	mymap['A'] = 10;
	mymap['B'] = 11;
	mymap['C'] = 12;
	mymap['D'] = 13;
	mymap['E'] = 14;
	mymap['F'] = 15;

	int wordCounter; // need to get the number of words somehow
	bool isLowtoHigh;
	int wordCount;
	


	
	int word;

	//example if data
	string data = "06000801"; 

	// would split the strings into 2
	string hex1 = data.substr(0, 4);
	string hex2 = data.substr(4, 4);

	// Just checking if they split correctly
	cout << hex1 << endl;
	cout << hex2 << endl;

	// converts them to decimal
	int decOfData1 = 0;
	for (int i = 0; i < 4; i++)
	{
		decOfData1 += mymap[hex1[i]] * pow(16, 3-i);
	}

	int decOfData2 = 0;
	for (int i = 0; i < 4; i++)
	{
		decOfData2 += mymap[hex2[i]] * pow(16, 3-i);
	}

	cout << decOfData1 << endl;
	cout << decOfData2 << endl;

	word = 40;
	/* 
	-Also will change variables when I figure out how to get
	the data to correspond with the correct word number.

	-Will change the if then statements to case, because this is 
	pretty ugly.

	-Still working on the shifting
	*/
	if (word == 0)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 << 1);
		resultBinary1 = (resultBinary1 >> 14);
		if (resultBinary1 == 0)
		{
			cout << "Rec_Ctrl = "<< resultBinary1 << " (no recording)" << endl;
		}
		else if (resultBinary1 == 2)
		{
			cout << "Rec_Ctrl = "<< resultBinary1 << " (no processing)" << endl;
		}
		else if (resultBinary1 == 3)
		{
			cout << "Rec_Ctrl = "<< resultBinary1 << " (processing & recording)" << endl;
		}
		else
			cout << "Rec_Ctrl = "<< resultBinary1 << " (unknown)" << endl;
	}

	if (word == 1)
	{
		int resultBinary2 = decOfData2;
		resultBinary2 = (resultBinary2 >> 13);
		if (resultBinary2 == 4)
		{
			cout << "Cmd_Type = " << resultBinary2 << " (Type A)" << endl;
		}
		else if (resultBinary2 == 5)
		{
			cout << "Cmd_Type = " << resultBinary2 << " (Type B)" << endl;
		}
		else if (resultBinary2 == 6)
		{
			cout << "Cmd_Type = " << resultBinary2 << " (Type C)" << endl;
		}
		else
			cout << "Cmd_Type = " << resultBinary2 << " (unknown)" << endl;
	}

	if (word == 4)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 << 15);
		resultBinary1 = (resultBinary1 >> 15);
		if (resultBinary1 == 0)
		{
			cout << "Rec_Raw = " << resultBinary1 << " (disabled)" << endl;
		}
		else if (resultBinary1 == 1)
			cout << "Rec_Raw = " << resultBinary1 << " (enabled)" << endl;
		else 
			cout << "Rec_Raw = " << resultBinary1 << " (unknown)" << endl;
	}

	if (word == 5)
	{
		int resultBinary2 = decOfData2;
		resultBinary2 = (resultBinary2 << 9);
		resultBinary2 = (resultBinary2 >> 9);
		cout << "Cmd_ID =" << resultBinary2 << endl;
	}

	if (word == 10)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 >> 11);
		cout << "Num_Responses = " << resultBinary1 << endl;
	}

	if (word == 15)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 << 13);
		resultBinary1 = (resultBinary1 >> 13);
		if (resultBinary1 == 0)
			cout << "Reset_Enable = " << resultBinary1 << " (disabled)" << endl;
		else if (resultBinary1 == 1)
			cout << "Reset_Enable = " << resultBinary1 << " (enabled)" << endl;
		else
			cout << "Reset_Enable = " << resultBinary1 << " (unknown)" << endl;
	}

	if (word == 22)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 << 12);
		resultBinary1 = (resultBinary1 >> 12);
		if (resultBinary1 == 0)
			cout << "Direction = " << resultBinary1 << " (Right)" << endl;
		else if (resultBinary1 == 1)
			cout << "Direction = " << resultBinary1 << " (Left)" << endl;
		else
			cout << "Direction = " << resultBinary1 << " (unknown)" << endl;
	}

	if (word == 32)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 << 1);
		resultBinary1 = (resultBinary1 >> 1);
		cout << "Num_Samples = " << resultBinary1 << " (Number of samples)" << endl;
	}

	if (word == 37)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 >> 15);
		if (resultBinary1 == 0)
			cout << "Parity = " << resultBinary1 << " (even)" << endl;
		else if (resultBinary1 == 1)
			cout << "Parity = " << resultBinary1 << " (odd)" << endl;
		else
			cout << "Parity = " << resultBinary1 << " (unknown)" << endl;
	}

	if (word == 38)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 << 1);
		resultBinary1 = (resultBinary1 >> 15);
		if (resultBinary1 == 0)
			cout << "Test = " << resultBinary1 << " (disabled)" << endl;
		else if (resultBinary1 == 1)
			cout << "Test = " << resultBinary1 << " (enabled)" << endl;
		else
			cout << "Test = " << resultBinary1 << " (unknown)" << endl;
	}

	if (word == 40)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 << 8);
		resultBinary1 = (resultBinary1 >> 15);
		if (resultBinary1 == 0)
			cout << "Ctrl_Enable = " << resultBinary1 << " (disabled)" << endl;
		else if (resultBinary1 == 1)
			cout << "Ctrl_Enable = " << resultBinary1 << " (enabled)" << endl;
		else
			cout << "Ctrl_Enable = " << resultBinary1 << " (unknown)" << endl;
	}

	if (word == 41)
	{
		int resultBinary1 = decOfData1;
		resultBinary1 = (resultBinary1 << 1);
		resultBinary1 = (resultBinary1 >> 9);
		cout << "Code = " << resultBinary1 << " (Code value)" << endl;
	}
	cout <<"\n\n";
	system("pause");
	return 0;
}