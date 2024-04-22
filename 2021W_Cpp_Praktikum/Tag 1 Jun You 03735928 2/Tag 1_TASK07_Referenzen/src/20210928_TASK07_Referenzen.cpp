//============================================================================
// Name        : 20210928_TASK07_Referenzen.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap(int& rPara_1, int& rPara_2)
{
	int iMiddle;
	iMiddle = rPara_1;
	rPara_1 = rPara_2;
	rPara_2 = iMiddle;
}

int main() {
	int i_1, i_2;
	cout << "Please enter two integers:" << endl;
	cin >> i_1 >> i_2;
	swap(i_1, i_2);
	cout << "i_2 = " << i_2 << endl;
	cout << "i_1 = " << i_1 << endl;
	return 0;
}
