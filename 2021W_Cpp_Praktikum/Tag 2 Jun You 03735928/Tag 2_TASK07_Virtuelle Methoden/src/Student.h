/*
 * Student.h
 *
 *  Created on: Sep 30, 2021
 *      Author: roku
 */

#ifndef STUDENT_H_
#define STUDENT_H_


#include "Person.h"

class Student:public Person
{
private:
	unsigned int m_uiStudentID;
public:
	Student(std::string sName, std::string sSurname, int iAge, unsigned int uiStudentID);
	~Student();
	unsigned int getStudentID();
	std::string getName(); //ueberschreibung
};

#endif /* STUDENT_H_ */
