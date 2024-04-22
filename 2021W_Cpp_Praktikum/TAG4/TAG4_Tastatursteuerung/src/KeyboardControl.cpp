/*
 * KeyboardControl.cpp
 *
 *  Created on: Oct 3, 2021
 *      Author: roku
 */


#include "InterfaceSIM.h"
#include "KeyboardControl.h"
#include <cmath>
#include "ncurses.h"

using namespace std;



KeyboardControl::KeyboardControl():
m_setVel({0.0,0.0}),m_getVel({0.0,0.0}),m_iMicros({1500,1500}),
MotorPID_l(PIDController(500,1850,0,0.04)),MotorPID_r(PIDController(500,1850,0,0.04))
{
	m_Interface.Initialize(0.04, KeyboardControl::transferFunction);
	transferPointer = this;

}

KeyboardControl::~KeyboardControl()
{}

void KeyboardControl::Communicate()
{
	// call Step() cyclicly
	sigprocmask(SIG_UNBLOCK, &m_Interface.mask, nullptr);

	initscr();


	/* first loop to get velocity from users */
	while(1)
	{
		int iNumber = getch();
		double p_setVel[2];
				p_setVel[0] = m_setVel[0];
				p_setVel[1] = m_setVel[1];

		if(iNumber == 113) // get input 'q', quit the first loop
			{m_setVel[0] = 0; m_setVel[1] = 0; break;}
		else if(iNumber == 98)
			{
				m_setVel[0] = 0; m_setVel[1] = 0;// get input 'b', break
			}
		else if(iNumber != -1)
		{
			/* assign the new target velocity if setVelocity would be inside [-0.5, 0.5] */

			switch(iNumber)
			{
			case 119: p_setVel[0] += 0.01;  p_setVel[1] += 0.01; break;// w
			case 115: p_setVel[0] -= 0.01;  p_setVel[1] -= 0.01; break; // s
			case 97:  p_setVel[0] += 0.005; p_setVel[1] -= 0.005; break;// a turn left
			case 100:  p_setVel[0] -= 0.005; p_setVel[1] += 0.005; break;// d turn right
			Default:  break;
			}
			if( ( fabs(p_setVel[0]) < 0.5) && ( fabs(p_setVel[1]) < 0.5) )
			{
				m_setVel[0] = p_setVel[0];
				m_setVel[1] = p_setVel[1];
			}


			clear();
			m_cBuffer = (char)iNumber;
			printw("Eingabe ist: %c \n", iNumber);

			printw("target velovity: %f,  %f \n", m_setVel[0], m_setVel[1]);
			printw("actual velovity: %f,  %f", m_getVel[0], m_getVel[1]);
		}
	}

	/* second loop to check realtime velocity */
	while( 1 )
	{
		if(fabs(m_getVel[0])+fabs(m_getVel[1]) == 0)
			{endwin();
			break;}
	}

	cout << "left velovity(m/s): " << m_getVel[1] << ". right velovity(m/s): " << m_getVel[0] << endl;
	cout << "Target left velovity(m/s): " << m_setVel[1] << ". Target right velovity(m/s): " << m_setVel[0] << endl;
	cout <<  m_cBuffer << endl;
	sigprocmask(SIG_BLOCK, &m_Interface.mask, nullptr);// terminate cyclic call
}


void KeyboardControl::Step()
{
	/*get the actual velocity */
	pdInput = m_Interface.GetInput();
	m_getVel[0] = pdInput[0];
	m_getVel[1] = pdInput[1];


	/* calculate u for each motor with a PID controller*/
	int m_Signal[2];
	MotorPID_r.CalculateU(m_setVel[0],m_getVel[0]);
	MotorPID_l.CalculateU(m_setVel[1],m_getVel[1]);
	m_Signal[0] = MotorPID_r.GetU()+ 1500;
	m_Signal[1] = MotorPID_l.GetU()+ 1500;


/* transfer the target Velocity into pmw signal length */
	if( abs(m_Signal[0]-1500) <= 500 && abs(m_Signal[1]-1500) <= 500)
	{
		m_iMicros[0] = m_Signal[0];
		m_iMicros[1] = m_Signal[1];
	}
	m_Interface.SetOutputs(m_iMicros);
}


KeyboardControl* KeyboardControl::transferPointer;

void  KeyboardControl::transferFunction()
{
	transferPointer->Step(); // call Step()
}
