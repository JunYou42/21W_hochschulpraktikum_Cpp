//============================================================================
// Name        : 20211002_Task06_Liste_von_Koordinaten.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

/*define a struct to represent coordinate*/
struct coord
{
	float m_x;
	float m_y;
	coord(float x, float y):m_x(x),m_y(y)
		{}
	int getx(){return m_x;}
	int gety(){return m_y;}
};

/* print all the elements in the list, pointer as input*/
void printlist(list<coord>* plist)
{
	list<coord>::iterator ite;
	for(ite = plist->begin(); ite != plist->end(); ite++)
		cout << "X: " << ite->m_x << ", Y: " << ite->m_y << endl;
}


/* delete elements as required, reference as input*/
void delcoords(list<coord>& refList)
{
	list<coord>::iterator ite;
	for(ite = refList.begin(); ite != refList.end(); ite++)
	{
		if(ite->m_x < ite->m_y)
			{ite = refList.erase(ite); ite--;}
			//delete list[n], list[n+1] becomes list[n];
			//iterator still points to list[n], to eliminate 'ite++', here is a 'ite--' needed
	}
}

int main() {
	srand((unsigned)time(nullptr));

	/* generate a list of coordinates randomly*/
	list<coord> lcList;
	for(int i=0; i<3; i++)
	{
		float f1,f2;
		f1 = (rand()*100.0)/RAND_MAX;
		f2 = (rand()*100.0)/RAND_MAX;
		lcList.push_back(coord(f1,f2));//initialize list[i] with f1,f2
	}

	/* print all the elements in the list*/
	cout << "Original list reads: " << endl;
	printlist(&lcList);

	/* copy the list*/
	list<coord> lcCopy (lcList);

	/* delete elements as required*/
	delcoords(lcList);

	/* display and compare*/
	cout << endl;
	cout << "Modified list reads: " << endl;
	printlist(&lcList);

	cout << endl;
	cout << "Copied list reads: " << endl;
	printlist(&lcCopy);


	return 0;
}
