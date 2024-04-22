/*
 * KeyboardControl.h
 *
 *  Created on: Oct 3, 2021
 *      Author: roku
 */

#ifndef KEYBOARDCONTROL_H_
#define KEYBOARDCONTROL_H_

#include "PIDController.h"
#include "InterfaceSIM.h"

class KeyboardControl
{
private:
	double m_setVel[2] ; // Sollgeschwindigkeit, 0 right, 1 left
	double m_getVel[2] ; // aktuelle Geschwindigkeit
	char m_cBuffer;
	PIDController MotorPID_r;
	PIDController MotorPID_l;

	int m_iMicros[2];
	double* pdInput;

public:
	KeyboardControl();
	~KeyboardControl();
	void Step();
	void Communicate();

	InterfaceSIM m_Interface;

	static KeyboardControl* transferPointer;
	static void transferFunction();

};



#endif /* KEYBOARDCONTROL_H_ */
