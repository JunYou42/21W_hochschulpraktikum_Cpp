//============================================================================
// Name        : 6.cpp
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
	Person* p_1 = new Student("Amily", "April", 16, 1);
	Person* p_2 = new Student("Bobby", "Brown", 16, 2);
	Person* p_3 = new Person("Cindy", "Coop", 17);

	cout << p_3->getName() << " " << p_3->getSurname() << " is " <<p_3-> getAge() << " years old."<< endl;
	cout << p_1->getName() << " " << p_1->getSurname() << " is " <<p_1-> getAge() << " years old."<< endl;
	return 0;
}
