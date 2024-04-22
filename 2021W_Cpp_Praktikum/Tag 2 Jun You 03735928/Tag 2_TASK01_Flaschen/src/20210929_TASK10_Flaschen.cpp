//============================================================================
// Name        : 20210929_TASK10_Flaschen.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Flaschen.h"

using namespace std;

int main() {
	Bottle Bottle_1, Bottle_2;

	//define Bottle 1
	Bottle_1.setVolume(18);
	Bottle_1.setMaterial("gold");
	cout << "Check Bottle_1:" << endl;
    Bottle_1.printBottle();

    //define Bottle 2
	Bottle_2.setVolume(90);
	Bottle_2.setMaterial("iron");
	cout << "Check Bottle_2:" << endl;
    Bottle_1.printBottle();

    //copy bottle_2's info to bottle_1 and display
	Bottle_1.adoptBottle(Bottle_2);
	cout << "Check Bottle_1:" << endl;
    Bottle_1.printBottle();

	return 0;
}
