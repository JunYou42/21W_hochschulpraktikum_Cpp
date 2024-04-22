//============================================================================
// Name        : 20211004_TAG4_Regler.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <fstream>
#include <string>

#include "PIDController.h"

using namespace std;


void read_file(string filename )// read a file and print each line
{
	string sOut;
	ifstream ifile;
	ifile.open(filename);
	if(ifile.is_open())
	{
		while(!ifile.eof())
		{
			getline(ifile,sOut);
			cout << sOut ;
		}
		ifile.close();
	}
}

int main() {

	double dy, dw;

	PIDController Ptest = PIDController(1000,10,0.1,0.5);

	ifstream iInFile;
	string sMessage;
	iInFile.open("PIDControllerInput.txt");
	if(iInFile.is_open())
	{
		while(!iInFile.eof())
		{
			getline(iInFile,sMessage);
			string sW, sY;
			int p = sMessage.find(" ");
			sW = sMessage.substr( 0, p-1);//[0,p-1]
			sY = sMessage.substr( p+1, 2*p);//[p+1, 2p]
			Ptest.CalculateU(stod(sW),stod(sY));
			cout << Ptest.GetU() << endl;
		}
		iInFile.close();
	}

	cout << "In comparison with" << endl;
	read_file("PIDControllerVgl.txt");

	return 0;
}
