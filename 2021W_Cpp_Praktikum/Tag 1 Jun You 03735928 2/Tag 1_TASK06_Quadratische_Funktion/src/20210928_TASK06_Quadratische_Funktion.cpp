//============================================================================
// Name        : 20210928_TASK06_Quadratische_Funktion.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

bool Equation(double a,double b,double c,double *dRef_1, double *dRef_2)
{
	double dDelta = pow(b,2)-4*a*c;
	if(dDelta<0)
	{
		return 0;
	}
	*dRef_1 = (-b+sqrt(dDelta))/(2*a);
	*dRef_2 = (-b-sqrt(dDelta))/(2*a);
	return 1;
}


int main() {
	double a, b, c;
	cout << "Please enter 3 parameters of an equation:" << endl;
	cin >> a >> b >> c;
	double dSol_1, dSol_2;
	if(Equation(a,b,c,&dSol_1, &dSol_2))
	{
		cout << "The solutions are = " << dSol_1  << " and " << dSol_2 << endl;
	}
	else
		cout << "No solution exists." << endl;

	return 0;
}
