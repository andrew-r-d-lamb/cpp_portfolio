#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int big, small;
	int i, j;	//counters
	int sum = 0;
	int square = 0;
	
	printf("Please enter 2 numbers:\nThe Second number must be smaller than the first number\n");
	scanf("%d %d", &big, &small);
	
	printf("You entered: %d, %d\n", big, small);	//test entered numbers
	
	//check that the second number entered is smaller than the first number
	while (big<small)
	{
		printf("The second number is not smaller than the first number, please enter a number smaller than %d", big);
		scanf("%d", &small);
	}

//PP1 Section A	
	//sum of all integers between 1 and big
	
	for (i=1; i<=big; i++)
	{
		//printf("i = %d\n", i);	//test value of i
		sum = sum + i;
		//printf("sum = %d\n", sum);	//test value of sum
	}	
	printf("Total of all integers between 1 and the big number is: %d\n", sum);
	
	//printf("\n\n\n\n\n");

//PP1 Section B	
	//sum of the squares of all even numbers between 1 and big

	sum = 0;
	for (i=1; i<=big; i++)
	{
		//printf("i = %d\n", i);	//test value of i
		if (i % 2 == 0) square = i * i;
		if (i % 2 != 0) square = 0;
		//printf("square = %d\n", square);	//test value of square
		sum = sum + square;
		//printf("sum = %d\n", sum);	//test value of sum
	}
	printf("Total sum of the squares of all the even numbers between 1 and the big number is: %d\n", sum);



//PP1 Section C	
	//create an array of length big		
	int bigArray[big];
	int product = 1;
	//assign integers to each element of the array
	for (i=0; i<=big; i++)
	{
		bigArray[i] = 1 + rand() % 100;	//use rand to create a not-truly "random" collection of numbers between 1 and 100.
		//printf("%d\n", bigArray[i]);
	}
	//get the product of all the multiples of 5 or 11 in the array
	for (i=0; i<big; i++)
	{
		if ((bigArray[i] % 5 == 0 || bigArray[i] % 11 == 0)) //&& (bigArray[i] != 0))
		{
			product = product * bigArray[i];
		}
	}
	printf("The product of all the multiples of either 5 or 11 is: %d\n", product);
	
	
//PP1 Section D	
	//display original contents of bigArray
	printf("Original Array:\n");
	for (i=0; i<big; i++)
	{
		printf("%d, ",bigArray[i]);
	}
	
	//sort bigArray
	int tempStorage;	//used to swap array elements
	
	for (i=1; i<big; i++)	//number of passes through loop
	{
		for (j=0; j<big-1; j++)	//number of comparisons per pass
		{
			if (bigArray[j] > bigArray[j+1])	//compare adjacent elements and swap if first is greater than second
			{
				tempStorage = bigArray[j];
				bigArray[j] = bigArray[j+1];
				bigArray[j+1] = tempStorage;
			}
		}
	}
	
	//display contents of sorted array
	printf ("\nSorted Array:\n");
	for (i=0; i<big; i++)
	{
		printf ("%d, ", bigArray[i]);
	}
	
	//display the small'th largest element in bigArray
	printf ("\nThe %d largest element in the bigArray is: %d\n", small, bigArray[big - small]);
	
	
	return 0;
}