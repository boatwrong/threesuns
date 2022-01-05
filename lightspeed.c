#include<stdio.h>
int main()
{
	double speedOfLight = 186000;
	double days;
	double distance;

	// take input
	printf("Please enter the number of days to travel: ");
	scanf("%lf", &days);

	// convert from mi/s to mi/day
	distance = days * speedOfLight * 60 * 60 * 24;

	// convert to million miles
	distance /= 1000;
	distance /= 1000;
	distance /= 1000;

	// print output
	printf("\n\n");
	printf("Distance traveled at\n");
	printf("   speed of light: %f million miles\n", distance);
}
