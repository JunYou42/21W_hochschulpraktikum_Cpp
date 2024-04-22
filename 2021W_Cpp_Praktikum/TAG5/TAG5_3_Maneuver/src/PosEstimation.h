/*
 * PosEstimation.h
 *
 *  Created on: Oct 5, 2021
 *      Author: roku
 */

#ifndef POSESTIMATION_H_
#define POSESTIMATION_H_

class PosEstimation
{
private:
	double x[3];
	double dVelAverage;

public:
	PosEstimation();
	void Reset();

	void PredictPosition(double dSpeedL, double dSpeedR, double dTimeStep);
	double* GetPosition();

};




#endif /* POSESTIMATION_H_ */
