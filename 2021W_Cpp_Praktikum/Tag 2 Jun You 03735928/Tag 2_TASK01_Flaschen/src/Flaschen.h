/*
 * Flaschen.h
 *
 *  Created on: Sep 29, 2021
 *      Author: roku
 */

#ifndef FLASCHEN_H_
#define FLASCHEN_H_

#include <string>

class Bottle
{
private:
	double dVolume;
	std::string sMaterial;

public:
	Bottle();
	~Bottle();

	double getVolume();
	void setVolume(double p_dVolume);
	std::string getMaterial();
	void setMaterial(std::string p_sMaterial);

	void printBottle();
	void adoptBottle(Bottle p_CopyBottle);
};



#endif /* FLASCHEN_H_ */
