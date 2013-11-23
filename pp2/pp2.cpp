/*************************************************************************************************

*Filename: pp2.cpp
*Authors: Andrew Lamb
*Last Modified: 03/03/2013
*Description:	User inputs 2 numbers - 	program 
												adds them together
												subtracts the smallest from the largest
												and displays results
												
*************************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	
	cout << "Please enter a number" << endl;
	cin >> num1;
	cout << "Please enter another number" << endl;
	cin >> num2;
	
	//add numbers together
	cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
	
	//subtract smaller number from larger number.  If same number, subtract one from the other
	if (num1 <= num2)	cout << num2 << "-" << num1 << "=" << num2 - num1 << endl;
	else cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
	
	return 0;
}