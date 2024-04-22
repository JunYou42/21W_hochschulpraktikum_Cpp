//============================================================================
// Name        : 20211001_Task02_Fibonacci-Folge.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int FibonacciRec(int n)
{
	int iResult = 1;
	if(n>2)
	{
		iResult = FibonacciRec(n-1) + FibonacciRec(n-2);
	}
	return iResult;
}

int main() {
	int iBuffer = 0;
	for(int i=1; i<16; i++)
	{
		iBuffer = FibonacciRec(i);
		cout << iBuffer << endl;
	}
	return 0;
}
