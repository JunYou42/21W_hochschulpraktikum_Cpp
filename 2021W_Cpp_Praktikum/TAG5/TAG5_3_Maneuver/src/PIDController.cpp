/*
 * PIDController.cpp
 *
 *  Created on: 04.10.2021
 *      Author: pi
 */



#include "PIDController.h"


PIDController::PIDController(double Kp, double Ki, double Kd, double Ta):
dKp(Kp),dKi(Ki),dKd(Kd),dTa(Ta),dEsum(0),deold(0),dU(0)
{}



void PIDController::CalculateU(double dW, double dY)
{
	double p_ek = dW-dY;
	dEsum = p_ek + deold;
	dU = dKp*p_ek + dKi*dTa*dEsum + dKd*(p_ek-deold)/dTa;
	deold = p_ek;//!!!
}


double PIDController::GetU()
{
	return dU;
}
