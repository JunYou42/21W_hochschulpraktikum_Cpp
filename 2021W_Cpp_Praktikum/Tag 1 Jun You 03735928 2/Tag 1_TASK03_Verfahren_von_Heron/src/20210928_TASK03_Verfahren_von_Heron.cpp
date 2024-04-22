//============================================================================
// Name        : 20210928_TASK03_Verfahren_von_Heron.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

double heron_ite(double input)
{
	double x = 49;
	for(int i=0;i<10;i++)
	{
		x = (x+input/x)/2;
	}
	return x;
}

int main() {
	double SqRoot;
	double iNum;

	/*get input*/
	cout << "Please enter a number:" ;
	cin >> iNum;

	/*use function to calculate the square root*/
	SqRoot = heron_ite(iNum);
	cout << "The square root is: " << SqRoot << endl;

	return 0;
}
