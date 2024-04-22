/*
 * square.cpp
 *
 *  Created on: Sep 30, 2021
 *      Author: roku
 */

#include "square.h"

square::square(int i_Input): m_ciSideLength(i_Input)
{}

square::square(const square& i_csCopy)
{
	m_ciSideLength = i_csCopy.getLength();
}

square::~square()
{}

int square::getLength() const
{return m_ciSideLength;}

int square::getPerimeter() const
{return m_ciSideLength*4;}

int square::getArea() const
{return m_ciSideLength*m_ciSideLength;}



