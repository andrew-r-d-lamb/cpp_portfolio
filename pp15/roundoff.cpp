#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


int main(int argc, char *argv[])
{

  cout << "------------------------------------------------------------------" << endl;
  cout << "Demonstration that 0.1 is not presented exactly in floating point." << endl;

  double x1 = 0.3;
  double x2 = 0.1+0.1+0.1;
  bool x1equaltox2 = (x1 == x2);

  cout << "x1 is set to 0.3" << endl;
  cout << "x2 is set to 0.1+0.1+0.1" << endl;
  cout << "However, the computer believes that 0.3=0.1+0.1+0.1 is " << x1equaltox2 << endl;
  cout << "In fact, 0.1+0.1+0.1=" << setprecision(20) << x2 << endl;
  cout << "0.3 - (0.1+0.1+0.1)=" << setprecision(20) << x1-x2 << endl;

  cout << "------------------------------------------------------------------" << endl;

  cout << "Press a key to continue ..." << endl;
  cin.get();

  cout << "------------------------------------------------------------------" << endl;
  cout << "Try the following square-root algorithm" <<endl;
  cout << "Enter a positive number and its square root is returned" << endl;
  cout << "Enter a negative number to exit" << endl;
  cout << "HOWEVER -- sometimes the program gets stuck in an infinite loop" << endl;
  cout << "Try to 20.0 for example" << endl;

  double c=1.0;
  char number[100];
  const int maxiters=100000;
  double EPSILON = 0.0;

  while ( cin.getline(number, 100, '\n') && (c = strtod(number,0))>=0.0)
    {
      double t = c;
      // compute the square root of a number c
      int numiters=0;
      while (t*t - c > EPSILON)
	{
	  t = (c/t + t) / 2.0;
	  numiters++;
	  if (numiters>maxiters)
	    {
	      cout << "Exiting because loop condition not true after "  << maxiters
		   << " iterations."<< endl;
	      break;
	    }
	}

      cout << "Loop terminated after " << numiters << " iterations." << endl;
      cout << setprecision(20) << c << "\troot=" << setprecision(20) 
	   << t << "\troot*root=" << setprecision(20) << t*t <<endl;
    }

  cout << "The lesson of this exercise is that " << endl;
  cout << "(a) we cannot expect exact answers using floating point " << endl;
  cout << "    but should seek an answer within some tolerance e.g. EPSILON=10e-15" << endl;
  cout << "(b) be careful to choose the right guard in a loop using floating points" << endl;
  cout << "    Do not use x==0.0" << endl;
  cout << "    A better choice in this case is to test the relative absolute error" << endl;
  cout << "    while ((fabs(t*t - c)>c*EPSILON))" << endl;

  cout << "------------------------------------------------" << endl;

  cout << "Press a key to continue ..." << endl;
  cin.get();

  cout << "------------------------------------------------" << endl;
  cout << "Harmonic Sum" << endl;
  cout << "------------------------------------------------" << endl;
  int sizeN[6]={100000,1000000,1000000, 100000000, 1000000000,2000000000};

  cout << "N\t\t\tSingle RtoL\t\tSingle LtoR\t\tDouble RtoL\t\tDouble LtoR" << endl;
  for (int j=0;j<6;j++)
    {
      double N = sizeN[j];
      cout << N << "\t";
      if (j<3)	cout << "\t";
      float sum1 = 0.0f;
      for (int i = 1; i <= N; i++)
	sum1 = sum1 + 1.0f / i;
      cout << sum1 << "\t";

      // using single precision, right-to-left
      float sum2 = 0.0f;
      for (int i = N; i >= 1; i--)
	sum2 = sum2 + 1.0f / i;
  
      cout << sum2 << "\t";

      // using double precision, left-to-right
      double sum3 = 0.0;
      for (int i = 1; i <= N; i++)
	sum3 = sum3 + 1.0 / i;

      cout << sum3 << "\t";
      
      // using double precision, right-to-left
      double sum4 = 0.0;
      for (int i = N; i >= 1; i--)
	sum4 = sum4 + 1.0 / i;
  
      cout << sum4 << endl;
    }

  cout << "Using single precision, the harmonic sum converges to a finite value." << endl;
  cout << "However, it is known that the harmonic sum diverges to infinity." << endl;

}


