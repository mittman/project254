#include "table.h"

Table::Table() {}
Table::~Table() {}

string const Table::getCode(const int wordPos, const string binString) {
	string field = "";
	string code = "";
	string desc = "";
	ostringstream resultString;

	char* endPtr;
	long mask = 0;
	long resultDecimal = 0;
	resultDecimal = strtol(binString.c_str(), &endPtr, 2);

	if (wordPos == 0) {
		resultDecimal &= ~(1 << 15);
		resultDecimal = (resultDecimal >> 13);
		//resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
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
		//mask = 111;
		resultDecimal = (resultDecimal >> 13);
		//resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
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
		//mask = 1;
		for (int i = 15; i > 0; i--)
			resultDecimal &= ~(1 << i);
		//resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Rec_Raw = ";

		if (code == "0") {
			desc = " (disable)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (enable)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 5) {
		for (int i = 15; i > 6; i--)
			resultDecimal &= ~(1 << i);
		//resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Cmd_ID = ";
		return field + code;
	}
	else if (wordPos == 10) {
		//mask = 11111;
		resultDecimal = (resultDecimal >> 11);
		//resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Num_Responses = ";
		return field + code;
	}
	else if (wordPos == 15) {
		//mask = 1;
		//resultDecimal = (resultDecimal >> 2);
		//resultDecimal = (resultDecimal & mask);
		for (int i = 15; i > 2; i--)
			resultDecimal &= ~(1 << i);
		resultDecimal = (resultDecimal >> 2);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Reset_Enable = ";

		if (code == "0") {
			desc = " (disable)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (enable)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 22) {
		//mask = 1;
		//resultDecimal = (resultDecimal >> 3);
		//resultDecimal = (resultDecimal & mask);
		for (int i = 15; i > 3; i--)
			resultDecimal &= ~(1 << i);
		resultDecimal = (resultDecimal >> 3);
		resultString << resultDecimal;
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
		resultDecimal &= ~(1 << 15);
		//resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Num_Samples = ";
		return field + code;
	}
	else if (wordPos == 37) {
		//mask = 1;
		//resultDecimal = (resultDecimal >> 15);
		resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
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
		//mask = 1;
		resultDecimal &= ~(1 << 15);
		resultDecimal = (resultDecimal >> 14);
		//resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Test = ";

		if (code == "0") {
			desc = " (disable)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (enable)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 40) {
		//mask = 1;
		for (int i = 15; i > 7; i--)
			resultDecimal &= ~(1 << i);
		resultDecimal = (resultDecimal >> 7);
		//resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Ctrl_Enable = ";

		if (code == "0") {
			desc = " (disable)";
			return field + code + desc;
		}
		else if (code == "1") {
			desc = " (enable)";
			return field + code + desc;
		}
		else {
			desc = " (unknown)";
			return field + code + desc;
		}
	}
	else if (wordPos == 41) {
		resultDecimal &= ~(1 << 15);
		resultDecimal = (resultDecimal >> 8);
		//resultDecimal = resultDecimal & mask;
		resultString << resultDecimal;
		code = resultString.str();
		field = "Code = ";
		return field + code;
	}
	else {
		return "";
	}
}
