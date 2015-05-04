#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//Going to put everything into a class function 
//after I get everything to workout

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

	int size; // need to get the number of words somehow
	int wordCount;
	vector<int> word(size);
	vector<int> fedData();
	vector<int> decOfData();

	bool isLowtoHigh(true);
	if (isLowtoHigh)
		for (int i = 0; i < ceil(size / 2); i++)
		{
			word[2 * i] = fedData(i).substr(0, 4); 
			word[(2 * i) + 1] = fedData(i).subtr(4, 4);
		}
	else
		for (int i = size; i <= 0; i--)
		{
			
		}

	
	/*
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

	*/


	/* 
	-Also will change variables when I figure out how to get
	the data to correspond with the correct word number.

	-Maybe change the if then statements to case

	-From what I checked the shifting works, just need the correct
	data to go along with it.
	*/
	
	if (word[0])
	{
		int resultBinary = decOfData[0];
		resultBinary = (resultBinary >> 13);
		resultBinary = (resultBinary & 4);
		if (resultBinary == 0)
		{
			cout << "Rec_Ctrl = "<< resultBinary << " (no recording)" << endl;
		}
		else if (resultBinary == 2)
		{
			cout << "Rec_Ctrl = "<< resultBinary << " (no processing)" << endl;
		}
		else if (resultBinary == 3)
		{
			cout << "Rec_Ctrl = "<< resultBinary << " (processing & recording)" << endl;
		}
		else
			cout << "Rec_Ctrl = "<< resultBinary << " (unknown)" << endl;
	}

	if (word[1])
	{
		int resultBinary = decOfData[1];
		resultBinary = (resultBinary >> 13);
		resultBinary = (resultBinary & 8);
		if (resultBinary == 4)
		{
			cout << "Cmd_Type = " << resultBinary << " (Type A)" << endl;
		}
		else if (resultBinary == 5)
		{
			cout << "Cmd_Type = " << resultBinary << " (Type B)" << endl;
		}
		else if (resultBinary == 6)
		{
			cout << "Cmd_Type = " << resultBinary << " (Type C)" << endl;
		}
		else
			cout << "Cmd_Type = " << resultBinary << " (unknown)" << endl;
	}

	if (word[4])
	{
		int resultBinary = decOfData[4];
		resultBinary = resultBinary & 2;
		if (resultBinary == 0)
		{
			cout << "Rec_Raw = " << resultBinary << " (disabled)" << endl;
		}
		else if (resultBinary == 1)
			cout << "Rec_Raw = " << resultBinary << " (enabled)" << endl;
		else 
			cout << "Rec_Raw = " << resultBinary << " (unknown)" << endl;
	}

	if (word[5])
	{
		int resultBinary = decOfData[5];
		resultBinary = resultBinary & 128;
		cout << "Cmd_ID =" << resultBinary << endl;
	}

	if (word[10])
	{
		int resultBinary = decOfData[10];
		resultBinary = (resultBinary >> 11);
		resultBinary = resultBinary & 32);
		cout << "Num_Responses = " << resultBinary << endl;
	}

	if (word[15])
	{
		int resultBinary = decOfData[15];
		resultBinary = (resultBinary >> 2);
		resultBinary = (resultBinary & 2);
		if (resultBinary == 0)
			cout << "Reset_Enable = " << resultBinary << " (disabled)" << endl;
		else if (resultBinary == 1)
			cout << "Reset_Enable = " << resultBinary << " (enabled)" << endl;
		else
			cout << "Reset_Enable = " << resultBinary << " (unknown)" << endl;
	}

	if (word[22])
	{
		int resultBinary = decOfData[22];
		resultBinary = (resultBinary >> 3);
		resultBinary = (resultBinary & 2);
		if (resultBinary == 0)
			cout << "Direction = " << resultBinary << " (Right)" << endl;
		else if (resultBinary == 1)
			cout << "Direction = " << resultBinary << " (Left)" << endl;
		else
			cout << "Direction = " << resultBinary << " (unknown)" << endl;
	}

	if (word[32])
	{
		int resultBinary = decOfData[32];
		resultBinary = resultBinary & 32768);
		cout << "Num_Samples = " << resultBinary << " (Number of samples)" << endl;
	}

	if (word[37])
	{
		int resultBinary = decOfData[37];
		resultBinary = (resultBinary >> 15);
		resultBinary = (resultBinary & 2);

		if (resultBinary == 0)
			cout << "Parity = " << resultBinary << " (even)" << endl;
		else if (resultBinary == 1)
			cout << "Parity = " << resultBinary << " (odd)" << endl;
		else
			cout << "Parity = " << resultBinary << " (unknown)" << endl;
	}

	if (word[38])
	{
		int resultBinary = decOfData[38];
		resultBinary = (resultBinary >> 14);
		resultBinary = (resultBinary & 2);
		if (resultBinary == 0)
			cout << "Test = " << resultBinary << " (disabled)" << endl;
		else if (resultBinary == 1)
			cout << "Test = " << resultBinary << " (enabled)" << endl;
		else
			cout << "Test = " << resultBinary << " (unknown)" << endl;
	}

	if (word[40])
	{
		int resultBinary = decOfData[40];
		resultBinary = (resultBinary >> 7);
		resultBinary = (resultBinary & 2);
		if (resultBinary == 0)
			cout << "Ctrl_Enable = " << resultBinary << " (disabled)" << endl;
		else if (resultBinary == 1)
			cout << "Ctrl_Enable = " << resultBinary << " (enabled)" << endl;
		else
			cout << "Ctrl_Enable = " << resultBinary << " (unknown)" << endl;
	}

	if (word[41])
	{
		int resultBinary = decOfData[41];
		resultBinary = (resultBinary >> 8);
		resultBinary = resultBinary & 128;
		cout << "Code = " << resultBinary << " (Code value)" << endl;
	}
	cout <<"\n\n";
	system("pause");
	return 0;
}
