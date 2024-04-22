/*
 * square.h
 *
 *  Created on: Sep 30, 2021
 *      Author: roku
 */

#ifndef SQUARE_H_
#define SQUARE_H_


class square
{
private:
	int m_ciSideLength;
public:
	square(int i_Input);
	square(const square& i_csCopy);
	~square();
	int getLength() const;// allow const object access
	int getPerimeter() const;
	int getArea() const;

};


#endif /* SQUARE_H_ */
