//============================================================================
// Name        : 8_Quadrate.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "square.h"

using namespace std;

square operator+(square i_S1,square i_S2)
{
	return square(i_S1.getLength()+i_S2.getLength());
}

square operator-(square i_S1,square i_S2)
{
	if(i_S1.getLength() > i_S2.getLength())
		{return square(i_S1.getLength() - i_S2.getLength());}
	cout<< "Invalid input. " ;
	return square(0);
}

std::ostream& operator<< (std::ostream &os, const square& csOut)
{
	return os << "Side Length = " << csOut.getLength() << ", Area = " << csOut.getArea() << ", Perimeter = " << csOut.getPerimeter() <<endl;
}

int main() {
	square S1(5); // task (a)

	cout << "Side Length:" << S1.getLength() << endl;
	cout << "Area:" << S1.getArea() << endl;
	cout << "Perimeter:" << S1.getPerimeter() << endl;// task (b)

	cout << endl;
	square S2(S1);
	cout << "Copied square's side length: " << S2.getLength() << endl;// task (c)

	cout << endl;
	square S1_2 = S1-S2;
	cout << "S1-S2 = " << S1_2.getLength() << endl;
	square S3(10);
	square S3_2 = S3-S2;
	cout << "S3-S2 = " << S3_2.getLength() << endl;//task(d)

	cout << endl;
	cout << "Square Info: " << S1 << endl; // task (e)
	return 0;
}
