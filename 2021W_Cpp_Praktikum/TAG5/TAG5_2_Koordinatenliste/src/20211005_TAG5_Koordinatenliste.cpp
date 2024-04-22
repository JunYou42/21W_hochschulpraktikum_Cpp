//============================================================================
// Name        : 20211005_TAG5_Koordinatenliste.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Maneuver.h"
using namespace std;


int main() {
	Maneuver MCircle, MEight;
	MCircle.CalcCircle(2.0,0.3,0.04);
	MEight.CalcEight(5.0,1.0,10.0);
	return 0;
}
