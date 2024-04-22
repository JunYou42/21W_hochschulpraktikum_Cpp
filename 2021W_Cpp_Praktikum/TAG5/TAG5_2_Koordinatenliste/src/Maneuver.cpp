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

Maneuver::Coord::Coord(){
	dX = 0;
	dY = 0;
	dV = 0.3;
}

Maneuver::Maneuver(){
}

Maneuver::~Maneuver()
{}

void Maneuver::CalcCircle(double dRadius, double dSpeed, double dTimestep)
{
	CoordList.clear(); //clear the list to store a new path
	for(int counter = 1; counter<(int)((2*M_PI)/((dSpeed/dRadius)*dTimestep)); counter++){
		Coord Cload;
		Cload.dX = dRadius * sin(counter*dSpeed/dRadius*dTimestep);
		Cload.dY = dRadius * (1-cos(counter*dSpeed/dRadius*dTimestep));
		CoordList.push_back(Cload);
	}
	LogList("LogFileCircle.txt");
}

void Maneuver::CalcEight(double dRadius, double dSpeed, double dTimestep){
	CoordList.clear();  //clear the list to store a new path
	for(int counter = 1; counter<(int)((2*M_PI)/((dSpeed/dRadius)*dTimestep)); counter++){
		Coord Cload1;
		Cload1.dX = dRadius * sin(counter*dSpeed/dRadius*dTimestep);
		Cload1.dY = dRadius * (1-cos(counter*dSpeed/dRadius*dTimestep));
		CoordList.push_back(Cload1);
	}

	for(int counter = 1; counter<(int)((2*M_PI)/((dSpeed/dRadius)*dTimestep)); counter++){
		Coord Cload2;
		Cload2.dX = dRadius * sin(counter*dSpeed/dRadius*dTimestep);
		Cload2.dY = -dRadius * (1-cos(counter*dSpeed/dRadius*dTimestep));
		CoordList.push_back(Cload2);
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


void Maneuver::CalcManeuverSpeed(double dX, double dY,double dW){}

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

