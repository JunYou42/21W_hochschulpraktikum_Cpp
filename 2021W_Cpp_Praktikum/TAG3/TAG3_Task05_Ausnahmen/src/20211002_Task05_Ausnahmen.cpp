//============================================================================
// Name        : 20211002_Task05_Ausnahmen.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>
#include <fstream>
using namespace std;


class nofileException:public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Die Datei existiert nicht.";
	}
};

void read_file(string filename )
{
	fstream ffile;
	ffile.open(filename);
	if(ffile.fail())
		throw nofileException{};// when file can nor be opened, throw a object of class nofileException

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

int main() {
	try
	{
		read_file("404.txt");
	}
	catch(nofileException& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
