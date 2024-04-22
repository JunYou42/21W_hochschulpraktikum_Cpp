/*
 * Vehicle.cpp
 *
 *  Created on: Sep 30, 2021
 *      Author: roku
 */

#include <iostream>
#include "Vehicle.h"
using namespace std;

int Vehicle::siCountID = 20210000; // initialization siCountID

/* --------------- constructor and destructor -------------*/


Vehicle::Vehicle(color p_Color, int p_Price, int p_Year):m_Color(p_Color),m_Price(p_Price),m_Year(p_Year)
{
	siCountID++;
	m_ID = siCountID;
	}

Vehicle::~Vehicle(){}

/* ----------------grab information -------------*/
int Vehicle::getID(){
	return m_ID;
}
int Vehicle::getYear(){
	return m_Year;
}
int Vehicle::getPrice(){
	return m_Price;
}


string Vehicle::getColor(){
	switch(m_Color){
		case(0):{return "blue";}
		case(1):{return "red";}
		case(2):{return "green";}
		case(3):{return "white";}
		case(4):{return "black";}
	}
}

/* --------------- print information -------------*/

void Vehicle::print(){
	cout << "Car_" << getID() << "'s Info" << endl;
	cout << "Color: " << getColor() << endl;
	cout << "Price/€: " << getPrice() << endl;
	cout << "Produced in " << getYear() << endl;
}

void Vehicle::getisOldTimer(const Vehicle& p_Vtest)
{
	if (p_Vtest.m_Year < 1980)
		cout << "This car is produced before 1980." << endl;
	cout << "This car is not produced before 1980." << endl;
}
