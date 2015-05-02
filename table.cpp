#include "table.h"

Table::Table() {}
Table::~Table() {}

/*
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
}
*/

string const Table::getCode(const int wordPos, string binString) {
	string field = "";
	string code = "";
	string desc = "";
	ostringstream resultString;

	int resultBinary = 0;
	stringstream ss;
	ss << binString;
	ss >> resultBinary;

	if (wordPos == 0) {
		//int resultBinary = decOfData[22];
		resultBinary = (resultBinary >> 13);
		resultBinary = (resultBinary & 0x11);
		resultString << resultBinary;
		code = resultString.str();
		field = "Rec_Ctrl = ";

		if (code == "0") {
			desc = " (no recording)";
			return field + code + desc;
		}
		else if (code == "2") {
			desc = " (no processing)";
			return field + code + desc;
		}
		else if (code == "3") {
			desc = " (processing & recording)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 1) {
		resultBinary = (resultBinary >> 13);
		resultBinary = (resultBinary & 0x111);
		resultString << resultBinary;
		code = resultString.str();
		field = "Cmd_Type = ";

		if (code == "4") {
			desc = " (Type A)";
			return field + code + desc;
		}
		else if (code == "5") {
			desc = " (Type B)";
			return field + code + desc;
		}
		else if (code == "6") {
			desc = " (Type C)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 4) {
		resultBinary = (resultBinary & 0x1);
		resultString << resultBinary;
		code = resultString.str();
		field = "Rec_Raw = ";

		if (code == "0") {
			desc = " (disabled)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (enabled)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 5) {
		resultBinary = (resultBinary & 0x1111111);
		resultString << resultBinary;
		code = resultString.str();
		field = "Rec_Raw = ";
		return field + code;
	}
	else if (wordPos == 10) {
		resultBinary = (resultBinary >> 11);
		resultBinary = (resultBinary & 0x11111);
		resultString << resultBinary;
		code = resultString.str();
		field = "Num_Responses = ";
		return field + code;
	}
	else if (wordPos == 15) {
		resultBinary = (resultBinary >> 2);
		resultBinary = (resultBinary & 0x1);
		resultString << resultBinary;
		code = resultString.str();
		field = "Reset_Enable = ";

		if (code == "0") {
			desc = " (disabled)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (enabled)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 22) {
		resultBinary = (resultBinary >> 3);
		resultBinary = (resultBinary & 0x1);
		resultString << resultBinary;
		code = resultString.str();
		field = "Direction = ";

		if (code == "0") {
			desc = " (Right)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (Left)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 32) {
		resultBinary = (resultBinary & 0x111111111111111);
		resultString << resultBinary;
		code = resultString.str();
		field = "Num_Samples = ";
		return field + code;
	}
	else if (wordPos == 37) {
		resultBinary = (resultBinary >> 15);
		resultBinary = (resultBinary & 0x1);
		resultString << resultBinary;
		code = resultString.str();
		field = "Parity = ";

		if (code == "0") {
			desc = " (even)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (odd)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 38) {
		resultBinary = (resultBinary >> 14);
		resultBinary = (resultBinary & 0x1);
		resultString << resultBinary;
		code = resultString.str();
		field = "Test = ";

		if (code == "0") {
			desc = " (disabled)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (enabled)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 40) {
		resultBinary = (resultBinary >> 7);
		resultBinary = (resultBinary & 0x1);
		resultString << resultBinary;
		code = resultString.str();
		field = "Ctrl_Enable = ";

		if (code == "0") {
			desc = " (disabled)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (enabled)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 41) {
		resultBinary = (resultBinary >> 8);
		resultBinary = resultBinary & 0x1111111;
		resultString << resultBinary;
		code = resultString.str();
		field = "Code = ";
		return field + code;
	}
	else {
		return "";
	}
}
