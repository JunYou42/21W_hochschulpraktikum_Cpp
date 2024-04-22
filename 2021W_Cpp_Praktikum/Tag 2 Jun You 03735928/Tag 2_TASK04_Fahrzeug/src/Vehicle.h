/*
 * Vehicle.h
 *
 *  Created on: Sep 30, 2021
 *      Author: roku
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle
{
public:
	enum color{blue, red, green, white, black};//1 color range

	Vehicle(color p_Color, int p_Price, int p_Year);
	~Vehicle();

	std::string getColor();//1 color
	int getPrice();// 2 price
	int getYear();// 3 year
	int getID();//4 ID

	void print();//information output
	static void getisOldTimer(const Vehicle& p_Vtest);

private:
	color m_Color;//1 color declaration
	int m_Price;// 2 price declaration
	int m_Year;// 3 produce year declaration
	int m_ID; // 4 ID
	static int siCountID;//4 !!! static variable for car counting

};




#endif /* VEHICLE_H_ */
