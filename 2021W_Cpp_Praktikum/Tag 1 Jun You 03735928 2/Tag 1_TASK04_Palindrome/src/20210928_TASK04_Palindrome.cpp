//============================================================================
// Name        : 20210928_TASK04_Palindrome.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string sTest)
{
	string sRev(sTest.rbegin(),sTest.rend());
	cout << sRev << endl;
	if(sRev == sTest)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main() {
	string sIn;
	cout << "Please enter a string: " << endl;
	cin >> sIn;
	if(isPalindrome(sIn))
	{
		cout << "Yes, it is a palindrome.";
	}
	else
	{
		cout <<"No, it is not a palindrome.";
	}
	return 0;
}
