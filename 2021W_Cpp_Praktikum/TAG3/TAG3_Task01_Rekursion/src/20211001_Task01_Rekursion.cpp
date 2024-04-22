//============================================================================
// Name        : 20211001_Task01_Rekursion.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int factorialIter(int iCalc) // ieterative way to get factorial
{
	int iResult=1;
	for(int i=iCalc;i>0;i--)
		{
		iResult = iResult*i;
		}
	return iResult;

}

int factorialRec(int iCalc) // recursive way to get factorial, invoking the fuction itself.
{
	int iResult = 1;
	if(iCalc!=1)
		{
		iResult = iCalc*factorialRec(iCalc-1);
		}
	return iResult;
}

int main() {
	cout << factorialIter(3) << endl;
	cout << factorialRec(3) << endl;

	return 0;
}
