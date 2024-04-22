/*
 * RobotControl.h
 *
 *  Created on: Oct 5, 2021
 *      Author: roku
 */

#ifndef ROBOTCONTROL_H_
#define ROBOTCONTROL_H_
#include "PIDController.h"
#include "InterfaceSIM.h"
#include "Maneuver.h"
#include "PosEstimation.h"

class RobotControl
{
private:
	InterfaceSIM interface;
	Maneuver maneuver;
	PosEstimation posEstimation;
	PIDController motorR;
	PIDController motorL;
	bool bIsActive;

public:
	RobotControl();
	static void transferFunction();
	static RobotControl* transferPointer;
	bool isActive();
	void Step();
	void Communicate();

};



#endif /* ROBOTCONTROL_H_ */
