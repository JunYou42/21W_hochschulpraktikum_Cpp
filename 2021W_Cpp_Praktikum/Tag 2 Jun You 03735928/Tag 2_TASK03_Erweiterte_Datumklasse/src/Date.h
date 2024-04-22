/*
 * Date.h
 *
 *  Created on: Sep 29, 2021
 *      Author: roku
 */
// Date.h

#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int m_day, m_month, m_year;

public:
	Date(int day, int month, int year);
	Date();
	~Date();

	int getDay();
	int getMonth();
	int getYear();

	void printDate();
	int compare(Date p_DRef);
};
#endif
