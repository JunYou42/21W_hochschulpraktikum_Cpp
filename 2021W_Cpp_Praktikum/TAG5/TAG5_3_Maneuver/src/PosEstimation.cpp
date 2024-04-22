/*
 * PosEstimation.cpp
 *
 *  Created on: Oct 5, 2021
 *      Author: roku
 */


#include "PosEstimation.h"
#include <cmath>

PosEstimation::PosEstimation():x({0,0,0}),dVelAverage(0)
{}


void PosEstimation::PredictPosition(double dSpeedL, double dSpeedR, double dTimeStep)
{

	x[0] = x[0] + dVelAverage*dTimeStep*cos(x[2]); // x
	x[1] = x[1] + dVelAverage*dTimeStep*sin(x[2]); // y
	x[2] = x[2] + dTimeStep*(dSpeedR-dSpeedL)/0.23;
	x[2] = fmod(x[2], 2*M_PI);// angle Wx
	if(x[2] >  M_PI)
		{x[2] -= 2*M_PI;}
	else if(x[2] < -M_PI)
		{x[2] += 2*M_PI;}
	dVelAverage = (dSpeedL + dSpeedR)/2;
}

double* PosEstimation::GetPosition()
{
	return x;
}

void PosEstimation::Reset()
{
	x[0]=0;
	x[1]=0;
	x[2]=0;
	dVelAverage = 0.0;
}
