//============================================================================
// Name        : Tag3_Task07_ncurses.cpp
// Author      : Jun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "ncurses.h"
#include <list>
#include "iostream"
using namespace std;

int main()
{
	int iNumber = 0;
	char cBuffer;
	list<char> clGet;
	list<char>::iterator ite;

	initscr();
/*	nodelay(stdscr,TRUE);
	noecho();*/

	while ( 1 )
	{
		int iNumber = getch();

		if(iNumber == 113)
			break;
		else if (iNumber != -1)
		{
			cBuffer = (char)iNumber;
			clGet.push_back(cBuffer);
			clear();
			printw("Eingabe ist: %c", iNumber);
		}
	}

	endwin();
	clGet.push_front('.');
	for(ite = clGet.end(); ite != clGet.begin(); ite--)
		cout << *ite;
		cout << endl;

	return 0;
}
