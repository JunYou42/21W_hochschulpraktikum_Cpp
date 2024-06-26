/*
 * Person.h
 *
 *  Created on: Sep 30, 2021
 *      Author: roku
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>

class Person
{
private:
	std::string m_sName;
	std::string m_sSurname;
	int m_iAge;

public:
	Person(std::string sName, std::string sSurname, int iAge);
	~Person();

	std::string getName();
	std::string getSurname();
	int getAge();
	bool setAge(int iAge);

};

#endif /* PERSON_H_ */
