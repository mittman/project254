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
		mask = 11;
		resultDecimal = (resultDecimal >> 13);
		resultDecimal = (resultDecimal & mask);
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
		mask = 111;
		resultDecimal = (resultDecimal >> 13);
		resultDecimal = (resultDecimal & mask);
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
		mask = 1;
		resultDecimal = (resultDecimal & mask);
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
		mask = 1111111;
		resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Cmd_ID = ";
		return field + code;
	}
	else if (wordPos == 10) {
		mask = 11111;
		resultDecimal = (resultDecimal >> 11);
		resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Num_Responses = ";
		return field + code;
	}
	else if (wordPos == 15) {
		mask = 1;
		resultDecimal = (resultDecimal >> 2);
		resultDecimal = (resultDecimal & mask);
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
		mask = 1;
		resultDecimal = (resultDecimal >> 3);
		resultDecimal = (resultDecimal & mask);
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
		mask = 111111111111111;
		resultDecimal = (resultDecimal & mask);
		resultString << resultDecimal;
		code = resultString.str();
		field = "Num_Samples = ";
		return field + code;
	}
	else if (wordPos == 37) {
		mask = 1;
		resultDecimal = (resultDecimal >> 15);
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
		mask = 1;
		resultDecimal = (resultDecimal >> 14);
		resultDecimal = (resultDecimal & mask);
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
		mask = 1;
		resultDecimal = (resultDecimal >> 7);
		resultDecimal = (resultDecimal & mask);
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
		mask = 1111111;
		resultDecimal = (resultDecimal >> 8);
		resultDecimal = resultDecimal & mask;
		resultString << resultDecimal;
		code = resultString.str();
		field = "Code = ";
		return field + code;
	}
	else {
		return "";
	}
}
