/*
 * Maneuver.h
 *
 *  Created on: Oct 5, 2021
 *      Author: roku
 */

#ifndef MANEUVER_H_
#define MANEUVER_H_
using namespace std;

#include <list>
#include <string>



class Maneuver
{
private:
	struct  Coord{
		double dX, dY, dV;
	//	Coord(double new_dX, double new_dY, double new_dV):dX(new_dX),dY(new_dY),dV(new_dV)
		Coord();
	};
	list<Coord> CoordList;
	list<Coord>::iterator iter;
	bool bIsRunning;
	double adWishSpeed[2];
	double dMaxSpeed;
	double dPosDifference;

public:
	Maneuver();
	virtual ~Maneuver();

	void CalcCircle(double dRadius, double dSpeed, double dTimestep);
	void CalcEight(double dRadius, double dSpeed, double dTimestep);
	void LogList(std::string sDateiname);
	bool isRunning();
	void Start();
	void Stop();
	void Proceed();
	void CalcManeuverSpeed(double dX, double dY,double dW);
	double* GetManeuverSpeed();

};



#endif /* MANEUVER_H_ */
