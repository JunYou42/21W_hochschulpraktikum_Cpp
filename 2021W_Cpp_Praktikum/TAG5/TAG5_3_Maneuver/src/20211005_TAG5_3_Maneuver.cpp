//============================================================================
// Name        : 20211005_TAG5_3_Maneuver.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "RobotControl.h"
using namespace std;

int main() {
	RobotControl Test;
	do{
		Test.Communicate();
	}
	while(Test.isActive());

	return 0;
}
