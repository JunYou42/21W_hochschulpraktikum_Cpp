//============================================================================
// Name        : 16_Fahrzeug.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Vehicle.h"

using namespace std;

int main() {
	Vehicle Volkswagen(Vehicle::red, 9800, 2011);//!color::red没用，要用Class::red/...
	Vehicle Benz_GT63(Vehicle::black, 209800, 2019);

	Benz_GT63.print();//with imported information
	Vehicle::getisOldTimer(Benz_GT63);

	return 0;
}
