#include "table.h"

Table::Table() {}
Table::~Table() {}

/*
{
Make sure the it's in decimal!!!!
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
		int mask = 11;
		resultBinary = (resultBinary & mask);
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
		int mask = 111;
		resultBinary = (resultBinary & mask);
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
		int mask = 1;
		resultBinary = (resultBinary & mask);
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
		int mask = 1111111;
		resultBinary = (resultBinary & mask);
		resultString << resultBinary;
		code = resultString.str();
		field = "Rec_Raw = ";
		return field + code;
	}
	else if (wordPos == 10) {
		int mask = 11111;
		resultBinary = (resultBinary >> 11);
		resultBinary = (resultBinary & mask);
		resultString << resultBinary;
		code = resultString.str();
		field = "Num_Responses = ";
		return field + code;
	}
	else if (wordPos == 15) {
		int mask = 1;
		resultBinary = (resultBinary >> 2);
		resultBinary = (resultBinary & mask);
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
		int mask = 1;
		resultBinary = (resultBinary >> 3);
		resultBinary = (resultBinary & mask);
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
		int mask = 111111111111111;
		resultBinary = (resultBinary & mask);
		resultString << resultBinary;
		code = resultString.str();
		field = "Num_Samples = ";
		return field + code;
	}
	else if (wordPos == 37) {
		int mask = 1;
		resultBinary = (resultBinary >> 15);
		resultBinary = (resultBinary & mask);
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
		int mask = 1;
		resultBinary = (resultBinary >> 14);
		resultBinary = (resultBinary & mask);
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
		int mask = 1;
		resultBinary = (resultBinary >> 7);
		resultBinary = (resultBinary & mask);
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
		int mask = 1111111;
		resultBinary = (resultBinary >> 8);
		resultBinary = resultBinary & mask;
		resultString << resultBinary;
		code = resultString.str();
		field = "Code = ";
		return field + code;
	}
	else {
		return "";
	}
}
