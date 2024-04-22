// Date.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Date.h"

Date::Date(int day, int month, int year)
{
 m_day = day; m_month = month; m_year = year;
}

Date::Date()
{
	//generate a random year between 1970~2030, which is not a leap year
	do {
	m_year = rand()%61+1970;}
	while(m_year%4 == 0 && m_year%100 != 0);

	//generate a random month
	m_month = rand()%12+1;

	//generate a random day
	switch(m_month){
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		m_day = rand()%31+1;
	case 2:
		m_day = rand()%28+1;
	default:
		m_day = rand()%30+1;
	}
}

Date::~Date(){} // add a destructor

int Date::getDay() {return m_day;}
int Date::getMonth() {return m_month;}
int Date::getYear() {return m_year;}


int Date::compare(Date p_DRef)// compare object and input date
{
	//convert both dates to number for simpler comparison
	// eg. 10.10.2010 ---> 20101010
	int i_0 = 1000*m_year+100*m_month+m_day;
	int iRef = 1000*p_DRef.m_year+100*p_DRef.m_month+p_DRef.m_day;

	if(i_0 < iRef)
		return 1;
	else if (i_0 == iRef){
		return 0;}
	return -1;
}

void Date::printDate()
{
	std::cout << getDay() << "." << getMonth() << "." << getYear() << std::endl;
}
