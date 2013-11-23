/*************************************************************************************************

*Filename: pp5.cpp
*Authors: Andrew Lamb
*Last Modified: 12/03/2013
*Description:	Program calculates pi to 10 decimal places using 
				pi = 4arctan(1.0) or pi = 4*the arctan of 1.0
				NB!!!  FLOAT PRECISE TO ABOUT 7 DIGITS, DOUBLE PRECISE TO ABOUT 16 DIGITS BEFORE GARBAGE.
												
*************************************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>	//included for setprecision() function

/*
	ARCTAN (x) = x - x^3/3 + x^5/5 - x^7/7 +...............
*/

using namespace std;

double arctanX (int no_of_iterations);
const int ITERATIONS = 1000000;

int main()
{
	double pi = 0.0;

	pi = 4 * arctanX(ITERATIONS);
	
	cout.precision (10);	
	cout << "The value of pi to 10 decimal places is: " << pi << endl;
		
	return 0;
}

double arctanX (int no_of_iterations)
{
	double aX = 0.0;
	double dX = 1.0;
	
	for (int i = 0; i < no_of_iterations; i++)
	{
		switch (i % 2)
		{
			case 0:	// if i  is an even number do this:
			{
				aX = aX + (pow(dX, (2 * i + 1))) / (2 * i + 1);
				//cout << "Added:" << arctanX << endl;	//test value of arctanX
				break;
			}
			case 1:	// if i is an odd number,do this:
			{
				aX = aX - (pow(dX, (2 * i + 1))) / (2 * i + 1);
				//cout << "Subtracted:" << arctanX << endl;	//test value of arctanX
				break;
			}
		}
		cout << setprecision(10) << "arctan of 1 is: " << aX << endl;
	}
	return aX;
}