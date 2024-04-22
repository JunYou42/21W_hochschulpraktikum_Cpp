//============================================================================
// Name        : 3_Vererbung.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Person.h"
#include "Student.h"

using namespace std;

int main() {
	Person P("Jane", "Doe", 25);
	Student S("John","Doe",49, 666);
	cout << "P's name: " << P.getName() << endl;
	cout << "S's name: " << S.getName() << endl;

	Person Pswitch("Johnny","Depp",58);
	cout << "Pswitch's name: " << Pswitch.getName() << endl;
	Student Safter("Judie","Foster", 59, 999);
	Pswitch = Safter; //?????
	cout << "Pswitch's name: " << Pswitch.getName()<< endl;

	return 0;
}
