/*
Filename:			pp16.cpp 

Authors: 			Andrew Lamb / Neil Hurley's calculation from pp16
Last Modified:	21/03/2013

PP16 Lab description:
Write a function
double rthroot(double x double r);
that computes the r th root of a number x. (For example, given r = 3, the
function should return the cube root).

The loop therefore should be:
while (...) 
{
t = (1 - 1/r)*t + c/(r * pow(t, r-1));
}
*/

#include <iostream>
//#include <cstdlib>			//included for strtod function
#include <iomanip>		//included for setprecision() function
#include <cmath>			//included for sqrt function

using namespace std;

double rthroot(double x, double r);	//function protoype for calculating the rth root of a number

int main()	
{
	double number;	
	double rth_number;
	double root_of_number;
	double power_of_number;

	cout << "************************************************************************" << endl;
	cout << "Neil's formula used to calculate the rth root of a number." << endl;
	cout << "Type in a positive number and press enter(-1 to exit): " << endl;	
	cin >> number;				//get number from user
	cout << "Type in a number to be used as rth_root number, e.g., '3' for calculating the cubed root:" << endl;
	
	while (number > 0.0)		//run loop while user number is greater than 0.0
    {
		cin >> rth_number;
		root_of_number = rthroot(number, rth_number);		//CALL FUNCTION TO CALCULATE THE SQUARE ROOT OF A NUMBER
		power_of_number = pow(root_of_number, rth_number);
		
		cout << "Neil's Calculation: " << setprecision(20) << number << "\troot=" << setprecision(20) << root_of_number << "\troot to the power of " << rth_number << " is:" << setprecision(20) << power_of_number << endl;	

		cout << "Enter another number or -1 to exit:" << endl;
		cin >> number;			//get another number from user
		cout << "Enter the rth number:" << endl;
	}
	
	return 0;
}

/**************************************************************************************************/
//FUNCTION TO CALCULATE THE RTH ROOT OF A NUMBER
double rthroot(double x, double r)
{
	double precision = 10e-10;
		
	double t = x;	
	// CALCULATE THE rth ROOT
	while (fabs(pow(t, r) - x) > precision)		//LOOP WHILE ABSOLUTE VALUE OF t^r is greater than precision	(fabs(pow(t,r) - x)>precision);
	{
		t = (1 - 1/r)*t + x/(r * pow(t, r-1));		//RTH ROOT CALCULATION IS:	t = (1 - 1/r)*t + c/(r * pow(t, r-1));
	}
	
	return t;	//RETURN T - THE VALUE FOR THE SQUARE ROOT OF THE NUMBER
}
/**************************************************************************************************/