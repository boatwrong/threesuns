#include<stdio.h>

int main()
{
	int x[10];
	int total;
	double average;

	// take input
	printf("Please enter 10 integer numbers\n");
	for(int i=0; i<10; i++)
	{
		scanf("%i", &x[i]);
	}

	// sum integers
	for(int i=0; i<10; i++)
	{
		total+=x[i];
	}

	//take avg
	average = total / 10.0;

	// output
	printf("Total is: %i\n", total);
	printf("Average is: %.2f\n", average);
}
