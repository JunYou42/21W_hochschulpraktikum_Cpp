//============================================================================
// Name        : 20211005_TAG5_PositionEstimation.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "PosEstimation.h"
#include <fstream>

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
			cout << sOut << endl ;
		}
		ifile.close();
	}
}

int main() {
	PosEstimation Test;

	ifstream iInFile;
	double s1,s2,s3;
	iInFile.open("PosEstimationInput.txt");
	if(iInFile.is_open())
	{
		while(!iInFile.eof())
		{
			iInFile >> s1 >> s2 >> s3;
			Test.PredictPosition(s2,s1,s3);
			cout << *Test.GetPosition() << "	" << *(Test.GetPosition()+1) << "	" << *(Test.GetPosition()+2) << endl;
		}
		iInFile.close();
	}

	cout << "In comparison with" << endl;
	read_file("PosEstimationVgl.txt");
	return 0;
}
