//============================================================================
// Name        : 20210929_TASK12_Erweiterte_Datumklasse.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	srand(time(nullptr));

	Date D_1(10,10,2001), D_2(10,10,1997), D_3; // randomly pick 3 dates

	cout << "D1 is: ";
	D_1.printDate();
	cout << "D2 is: ";
	D_2.printDate();
	cout << "D3 is: ";
	D_3.printDate(); // print all the date

	cout << "D_1 VS D_2 : "<< D_1.compare(D_2) << endl;
	cout << "D_1 VS D_3 : "<< D_1.compare(D_3) << endl;
	cout << "-1:before; 0:equal; 1:after";
	return 0;
}
