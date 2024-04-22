//============================================================================
// Name        : 20210927_TASK02_Maya_Zahlen.cpp
// Author      : STONE
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
	int iNum=0;
	string t;
	string str;
	string sVig = "0123456789ABCDEFGHIJ";
	cout << "Please enter a number in decimal numeral system:" << endl;
	cin >> iNum;
	while(iNum!=0)	//  use string str to store the numbers
	{
		t = sVig[iNum%20];
		str.append(t);
		cout << t << endl;
		iNum = iNum/20;
	}

	string sReverse(str.rbegin(),str.rend());// reverse string str to get the number in correct order
	cout << "The corresponding number in vigesimal numeral system is: " << sReverse << endl;
	return 0;
}
