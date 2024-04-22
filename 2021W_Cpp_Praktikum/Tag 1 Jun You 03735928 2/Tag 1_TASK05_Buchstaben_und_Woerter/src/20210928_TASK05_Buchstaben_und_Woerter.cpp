//============================================================================
// Name        : 20210928_TASK05_Buchstaben_und_Woerter.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string mess(string sGet)
{
	int n = sGet.size();
	string sMess;
	/* first letter */
	sMess.append(1,sGet[0]);

	/* middle part*/
	for(int i = 1;( (n-i) > 2 || ((n-i)<=2 && pow(-1,i)==1)); i++)
	{
		sMess.append(1,sGet[i-pow(-1,i)]);
//		cout << "n= "<< n << " i="<<i <<" sMess="<< sMess << endl;
	}

	/* add the rest, one letter for even number, two letter for odd number*/
	int i = sMess.size();
	int iRest = n-i;
	string sRest = sGet.substr(i,iRest);
	sMess.append(sRest);

	return sMess;
}

string extract(string sGet)
{
	string sExt;
	for(int i=0; i<sGet.size();i++)
	{
		switch(sGet[i])
		{
		case 97:// remove a
			break;
		case 0x65:// remove e
			break;
		case 0x69:// remove i
			break;
		case 0x6F:// remove o
			break;
		case 0x75:// remove u
			break;
		default:
			sExt.append(1,sGet[i]);
		}
	}
	return sExt;
}

int main() {
	string sGet;
	cout << "Please enter a word:" << endl;
	cin >> sGet;
	cout << "In wrong order reads: " << mess(sGet) << endl;
	cout << "Without vowols reads: " << extract(sGet) << endl;
	return 0;
}
