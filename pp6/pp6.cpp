/*************************************************************************************************

*Filename: pp6.cpp
*Authors: Andrew Lamb
*Last Modified: 12/03/2013
*Description:	Program calculates pi to 10 decimal places using 
				pi = 4 * (4arctan(1/5) - arctan(1/239))
												
*************************************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>	//included for setprecision() function

using namespace std;

double arctanX (int no_of_iterations, double dX);
const int ITERATIONS = 20;

int main()
{
	double pi = 0.0;
	double dX, dY;
	
	dX = 1.0/5.0;
	dY = 1.0/239.0;
	pi = 4 * (4*arctanX(ITERATIONS, dX) - arctanX(ITERATIONS, dY));
	
	cout.precision (11);	
	cout << "The value of pi to 10 decimal places is: " << pi << endl;
		
	return 0;
}

double arctanX (int no_of_iterations, double dX)
{
	double aX = 0.0;
	
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