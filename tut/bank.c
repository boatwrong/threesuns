#include<stdio.h>

void printErrorMessage()
{
	printf("Incorrect value entered, returning to main menu\n");
}

void changeBalance(float x, float *balance)
{
	*balance += x;
}

// prompt user to exit program or return to main menu
int promptExit()
{
	int x;
	do {
		printf("Return to main menu?\n Enter: \n\t1 for yes\n\t0 for no\n");
		scanf("%i", &x);
	} while(x < 0 || x > 1);
	if(x == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// print main menu
void printMain()
{
	printf("\n");
	printf("Please select an option by entering it's number on the list\n");
	printf("\n");
	printf("1. Show Balance\n");
	printf("2. Deposit\n");
	printf("3. Withdraw\n");
	printf("4. Exit\n");
	printf("\n");
}

// prompt input from user
int input() 
{
	int x;
	do {
		printf("Please enter a number from 1-4\n\n");
		scanf("%i", &x);
	} while(x < 1 || x > 4);
	return x;
}

int main()
{

	float balance = 0;
	int x;

	do {
		printMain();
		x = input();
		if(x ==1)
		{
			printf("Balance:\n");
			printf(" %.2f\n\n", balance);
			if(!promptExit())
			{
				// exit program
				x=4;
			}
		}

		else if(x == 2)
		{
			float y;
			printf("option 2\n");
			printf("Enter amount to deposit:\n");
			scanf("%f", &y);
			
			changeBalance(y, &balance);

			if(!promptExit())
			{
				// exit program
				x=4;
			}	
		}

		else if(x == 3)
		{
			float z;
			printf("option 3\n");
			printf("Enter amount to withdraw:\n");
			scanf("%f", &z);

			if(z <= balance)
			{
				changeBalance(z*(-1), &balance);
			}

			if(!promptExit())
			{
				// exit program
				x=4;
			}
		}

	} while(x != 4);

	return 0;
}

