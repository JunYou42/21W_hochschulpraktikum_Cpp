//============================================================================
// Name        : 20211002_Task04_Dateien_lesen_und_schreiben.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
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
			cout << sOut << endl;
		}
		ifile.close();
	}
}

int write_file(string filename)// open a file, append some input line until we get 'exit'
{
	string sIn;
	ofstream ofile;// for writing
	ofile.open(filename, ios::out|ios::app);
	if(ofile.is_open())
		while(1)
		{
			cout << "Please append a line (quit by typing 'exit'):" << endl;
			getline(std::cin,sIn);//store the typed string in sIn
			if (sIn=="exit"){
				ofile.close();
				return 0;
			}
			ofile << sIn << '\n';//write sIn in file
		}
	return 1;
}

int main() {
/*	fstream ffile;
	ffile.open("Test.txt",ios::out);*/

		read_file("Test.txt");

		write_file("Test.txt");

		read_file("Test.txt");

	return 0;
}
