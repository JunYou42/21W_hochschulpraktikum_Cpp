//============================================================================
// Name        : 20210925_TASK01_Taschenrechner.cpp
// Author      : STONE
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	float iNumber_1 = 0;
	cout << "Please enter the first number:";
	cin >> iNumber_1;
// ensure a required input
	while(cin.fail())
	{
		std::cout <<"please enter a number"<< std::endl;
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		std::cin >> iNumber_1;
	}

	char chOperator;
	cout << "Please enter an operator from +-*/:";
	cin >> chOperator;
	while(chOperator != '+' && chOperator != '-' && chOperator != '*' && chOperator != '/')
	{
		std::cout <<"Please enter an operator from +-*/:"<< std::endl;
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		std::cin >> chOperator;
	}


	float iNumber_2 = 0;
	cout << "Please enter the second number:";
	cin >> iNumber_2;
	// ensure a required input
		while(cin.fail())
		{
			std::cout <<"please enter a number"<< std::endl;
			std::cin.clear();
			std::cin.ignore(1000,'\n');
			std::cin >> iNumber_1;
		}

		switch(chOperator)
			{
			case 0x2B:
				cout << iNumber_1 << '+' << iNumber_2 << '=' << iNumber_1+iNumber_2;
				break;
			case 0x2D:
				cout << iNumber_1 << '-' << iNumber_2 << '=' << iNumber_1-iNumber_2;
				break;
			case 0x2A:
				cout << iNumber_1 << '*' << iNumber_2  << '=' << iNumber_1*iNumber_2;
				break;
			case 0x2F:
				if(iNumber_2 == 0)
				{
					cout << "Calculation failed. Please enter an non-zero number:";
					cin >> iNumber_2;
					// ensure a required input
							while(cin.fail())
							{
								std::cout <<"please enter a number"<< std::endl;
								std::cin.clear();
								std::cin.ignore(1000,'\n');
								std::cin >> iNumber_1;
							}
				}
				cout << iNumber_1 << '/' << iNumber_2 << '=' << iNumber_1/iNumber_2;
				break;
			}

        return 0;
}

