/*
 * RobotControl.cpp
 *
 *  Created on: Oct 5, 2021
 *      Author: roku
 */

#include "RobotControl.h"
#include "PIDController.h"
#include "InterfaceSIM.h"
#include "Maneuver.h"
#include "PosEstimation.h"

#include <cmath>
#include <iostream>
#include "ncurses.h"

using namespace std;

RobotControl::RobotControl() :motorR(500.0,100.0,0.0,0.04),motorL(500.0,100.0,0.0,0.04){
	interface.Initialize(0.04, RobotControl::transferFunction);
	transferPointer = this;
	bIsActive = 1;
}

void RobotControl::transferFunction(){
	transferPointer->Step();
}

RobotControl* RobotControl::transferPointer;

bool RobotControl::isActive(){
	return bIsActive;
}

void RobotControl::Communicate(){
	double radius ;
	double speed ;
	cout<<"Please enter a radius:"<< endl;
	cin >> radius;
	cout<<"Please enter a speed:" << endl;
	cin >> speed;


	//get the instruction from user
	string order;
	cout<<"Do you want to build a new maneuver? please type Yes or No"<<std::endl;
	cin >> order;
	posEstimation.Reset();

	if(order == "Yes"){
		// get the trajectory type from user
		cout << "what kind of trajectory do you want to generate: Circle or Eight "<< endl;
		cin >> order;
		if(order == "Circle"){
			maneuver.CalcCircle(radius,speed,0.04);
		}
		else if(order == "Eight"){
			maneuver.CalcEight(radius,speed,0.04);
		}

		//start Ncurses
		initscr();
		nodelay(stdscr,TRUE);
		noecho();
		// call Step() cyclicly
		sigprocmask(SIG_UNBLOCK, &interface.mask, nullptr);

		/* first loop to get velocity from users */
		printw("s:Start, b:Stop, w:Proceed, q:quit");
		while(1)
		{
			string m_cBuffer;
			int iNumber = getch();
			if(iNumber == 113) // get input 'q', quit the first loop
				{maneuver.Stop(); break;}
			else if(iNumber != -1)
			{
				clear();
				switch(iNumber)
				{
				case 119: maneuver.Proceed(); printw("Proceed"); break;/// w for proceed
				case 115:  maneuver.Start(); printw("Start"); break; // s for start
				case 98:  maneuver.Stop(); printw("Stop"); break; // b for stop
				Default:  break;
				}
				m_cBuffer = (char)iNumber;
				printw("\n Get Input: %c \n", iNumber);
			}
		}



		/* second loop to check realtime velocity */
		double* pdInput = interface.GetInput();
		while( 1 )
		{
			if(fabs(pdInput[0])+fabs(pdInput[1]) == 0){
				bIsActive = false;
				endwin();
				break;}
		}

		sigprocmask(SIG_BLOCK, &interface.mask, nullptr);// terminate cyclic call
	}
	else if(order == "No"){
		bIsActive = false;
	}
}

void RobotControl::Step(){
	/*get the actual velocity */
	double* pdInput = interface.GetInput();

	int	p_iMicros[2];

	if(maneuver.isRunning() == true){
		// get predicted position
		double* dPre;
		posEstimation.PredictPosition(pdInput[1], pdInput[0], 0.04);
		dPre = posEstimation.GetPosition();

		// Calculated target velocity
		maneuver.CalcManeuverSpeed(dPre[0], dPre[1], dPre[2]);
		double* m_setVel ;
		m_setVel = maneuver.GetManeuverSpeed();

		/* calculate u for each motor with a PID controller*/
		int m_Signal[2];
		motorR.CalculateU(m_setVel[0],pdInput[0]);
		motorL.CalculateU(m_setVel[1],pdInput[1]);
		m_Signal[0] = motorR.GetU()+ 1500;
		m_Signal[1] = motorL.GetU()+ 1500;


		/* transfer the target Velocity into pmw signal length */
		if( abs(m_Signal[0]-1500) <= 500 && abs(m_Signal[1]-1500) <= 500)
		{
			p_iMicros[0] = m_Signal[0];
			p_iMicros[1] = m_Signal[1];
		}
	}
	else if(maneuver.isRunning() == false){
		p_iMicros[0] = 1500;
		p_iMicros[1] = 1500;
	}

	// send target velocity to robot
	interface.SetOutputs(p_iMicros);

}
