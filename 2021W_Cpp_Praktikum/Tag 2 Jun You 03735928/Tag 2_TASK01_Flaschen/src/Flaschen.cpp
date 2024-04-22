
#include "Flaschen.h"
#include <iostream>
#include <string>

Bottle::Bottle(): dVolume(100), sMaterial("wood")
{
}

Bottle::~Bottle()
{}

void Bottle::setVolume(double p_dVolume)
{
	dVolume = p_dVolume;
}

double Bottle::getVolume()
{
	return dVolume;
}


std::string Bottle::getMaterial()
{
	return sMaterial;
}

void Bottle::setMaterial(std::string p_sMaterial)
{
	sMaterial = p_sMaterial;
}

void Bottle::printBottle()
{
	std::cout << "This " << getMaterial() << " bottle contains " << getVolume() << "L water." << std::endl;
}

void Bottle::adoptBottle(Bottle p_CopyBottle)
{
	dVolume = p_CopyBottle.getVolume();
	sMaterial = p_CopyBottle.getMaterial();
}









