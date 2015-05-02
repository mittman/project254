#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main(){
	
	char* ptr;
	string s = "0001000011111011";
	//char* str = s;
	long parsed = strtol(s.c_str(), &ptr, 2);
	
	parsed = (parsed >> 13);
	parsed = (parsed &4);
	
	cout << parsed << endl;
  	

	return 0;


}
