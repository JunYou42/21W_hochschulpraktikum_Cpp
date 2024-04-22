/*
 * Maneuver.cpp
 *
 *  Created on: Oct 5, 2021
 *      Author: roku
 */

#include "Maneuver.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <list>
#include <string>
using namespace std;

Maneuver::Coord::Coord():dX(0.0),dY(0.0),dV(0.3)//initialize velocity!
{
/*	dX = 0;
	dY = 0;
	dV = 0.3;*/
}

Maneuver::Maneuver(){
	bIsRunning = 0;
	adWishSpeed[2]={0};
	dMaxSpeed = 0.5;
	dPosDifference = 0.02;
}


Maneuver::~Maneuver()
{}

void Maneuver::CalcCircle(double dRadius, double dSpeed, double dTimestep)
{
	CoordList.clear(); //clear the list to store a new path
	for(int counter = 1; counter<(int)((2*M_PI)/((dSpeed/dRadius)*dTimestep)); counter++){

		Cload.dX = dRadius * sin(counter*dSpeed/dRadius*dTimestep);
		Cload.dY = dRadius * (1-cos(counter*dSpeed/dRadius*dTimestep));
		CoordList.push_back(Cload);
	}
	LogList("LogFileCircle.txt");
}

void Maneuver::CalcEight(double dRadius, double dSpeed, double dTimestep){
	CoordList.clear();  //clear the list to store a new path
	for(int counter = 1; counter<(int)((2*M_PI)/((dSpeed/dRadius)*dTimestep)); counter++){

		Cload.dX = dRadius * sin(counter*dSpeed/dRadius*dTimestep);
		Cload.dY = dRadius * (1-cos(counter*dSpeed/dRadius*dTimestep));
		CoordList.push_back(Cload);
	}

	for(int counter = 1; counter<(int)((2*M_PI)/((dSpeed/dRadius)*dTimestep)); counter++){

		Cload.dX = dRadius * sin(counter*dSpeed/dRadius*dTimestep);
		Cload.dY = -dRadius * (1-cos(counter*dSpeed/dRadius*dTimestep));
		CoordList.push_back(Cload);
	}
	LogList("LogFileEight.txt");
}

/* print list CoordList out*/
void Maneuver::LogList(std::string sDateiname){
	std::ofstream ofile;
	ofile.open(sDateiname,std::ios::out |  std::ios::trunc);
	if (ofile.is_open()){
		for (iter = CoordList.begin(); iter != CoordList.end(); iter++)
		{
			ofile<< iter->dX <<'\t'<< iter-> dY << std::endl;
		}
	}
	else{
		cout << "Unable to open file";
		}
	ofile.close();
}


void Maneuver::CalcManeuverSpeed(double dX, double dY,double dW){
	//Position comparison
	//double dDiff = sqrt( pow(dX- iter->dX, 2) + pow(dX- iter->dX, 2));// x, y seperately

	if( fabs(dX- iter->dX) < dPosDifference && fabs(dY- iter-> dY) < dPosDifference)
		iter++;

	//test if the iterator in at the end of list
	if( iter == CoordList.end() )
	{
		adWishSpeed[0] = 0.0;
		adWishSpeed[1] = 0.0;
		Stop();
	}
	else{
		// angle between target position and present position
		double phi = atan2(iter->dY-dY, iter->dX-dX);
		// angle difference
		double delta = phi - dW;
		//standalize the angle between [-pi,pi]
		 delta = fmod(delta, 2*M_PI);
		 if (delta > M_PI){
			 delta -= 2*M_PI;
			}
		 else if(delta <= -M_PI){
			 delta += 2*M_PI;
			}
		 //rotational velocity
		 double dRot = 2*delta;
		 if(dRot > 0.5){
			 dRot = 0.5;
		 }
		 else if(dRot < -0.5){
			 dRot = -0.5;
		 }
		 //translational velocity
		 double dTra = iter->dV;
		 //check the velocity
		 if(dRot * dTra > 0 ){
			 if( dRot + dTra > dMaxSpeed ){
				 dTra = dMaxSpeed - dRot;
			 }
			 else if(dTra + dRot < -dMaxSpeed ){
				 dTra = -dMaxSpeed - dRot;
			 }
		 }
		 else if (dRot*dTra < 0){
			 if( dTra - dRot > dMaxSpeed ){
				 dTra = dMaxSpeed + dRot;
			 }
			 else if(dTra - dRot < -dMaxSpeed){
				 dTra = -dMaxSpeed + dRot;
			 }
		 }
		// positive rotaion = turn left: vel_right +, vel_left -
		adWishSpeed[0] = dTra + dRot;
		adWishSpeed[1] = dTra - dRot;
	}
}

double* Maneuver::GetManeuverSpeed(){return adWishSpeed;}

bool Maneuver::isRunning(){return bIsRunning;}

void Maneuver::Start(){
	iter = CoordList.begin();
	bIsRunning = 1;
}

void Maneuver::Stop(){
	bIsRunning = 0;
}
void Maneuver::Proceed(){
	bIsRunning = 1;
}

