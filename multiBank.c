#include<stdio.h>
#include<stdlib.h>

int promptExit()
{
	int x;
	do {
		printf("Would you like to return to main menu?\n");
		printf("\t1. return to main\n");
		printf("\t0. Exit\n");
		scanf("%d", &x);
	} while(x < 0 || x > 1);

	return x;
}

void listAccounts(float accounts[])
{
	int i=0;
	while(accounts[i] > -1)
	{
		printf("\tAccount %d: $%.2f\n", (i + 1), accounts[i]);
		i++;
	}
	printf("\n");
}

void deposit(float *accounts)
{
	int account;
	float value;

	listAccounts(accounts);

	printf("\n\nPlease select the account you would like to deposit to.\n");
	scanf("%d", &account);
	
	while(accounts[account-1] < 0)
	{
		system("clear");
		printf("Please select a valid account to deposit to: \n\n");
		listAccounts(accounts);
		scanf("%d", &account);
	}


	printf("please enter the amount you would like to deposit:\n");
	scanf("%f", &value);
	accounts[account-1] += value;
}

void withdraw(float *accounts)
{
	int account;
	float value;

	listAccounts(accounts);
	
	printf("\n\nPlease select the account you would like to make a withdrawal from.\n");
	scanf("%d", &account);

	while(account > 4 || account < 0 || accounts[account-1] < 0)
	{
		system("clear");
		listAccounts(accounts);
		printf("Please select a valid account to deposit to: \n\n");
		scanf("%d", &account);
	}

//	while(accounts[account-1] < 0)
//	{
//		system("clear");
//		listAccounts(accounts);
//		printf("Please select a valid account to deposit to: \n\n");
//		scanf("%d", &account);
//	}

	printf("please enter the amount you would like to withdraw:\n");
	scanf("%f", &value);

	while(accounts[account-1] - value < 0)
	{
		printf("You cannot withdraw into a negative balance.\n");
		printf("Please enter an appropriate value to withdraw.\n");
		scanf("%f", &value);
	}

	accounts[account-1] -= value;
}


int addAccount(float accounts[])
{
	printf("Account opened, current balance: $0.00\n\n");
	
	int newLength = 0;
	int i=0;

	while(accounts[i] >= 0)
	{
		newLength++;
		i++;
	}
	
	return newLength;
}

void printMain()
{
	printf("*****************************************************************\n");
	printf("\n                     Main Menu\n\n");
	printf("Select an option from the list below:\n");
	printf("\n\t1: Open Account\n");
	printf("\t2. List Accounts\n");
	printf("\t3. Deposit\n");
	printf("\t4. Withdraw\n");
	printf("\t5. Exit\n\n");
	printf("*****************************************************************\n");
}

int main()
{
	system("clear");
	// each value in array represents account value
    float accounts[5] = {-1, -1 , -1, -1, -1};

	int x;
	do {
		printMain();
		printf("Please select a number from 1 - 5\n");
		scanf("%d", &x);
		if(x < 1 || x > 5)
		{
			do {
				system("clear");
				printMain();
				printf("Incorrect option selected.\n\n");
				printf("Please select a number from 1 to 5\n");
				scanf("%d", &x);
			} while(x < 1 || x > 5);
		}

		if(x == 1)
		{
			accounts[addAccount(accounts)] = 0;

			if(!promptExit())
			{
				break;
			}
			system("clear");
		}

		else if(x == 2)
		{
			listAccounts(accounts);
			if(!promptExit())
			{
				break;
			}
			system("clear");
		}

		else if(x == 3)
		{
			deposit(accounts);
			if(!promptExit())
			{
				break;
			}
			system("clear");
		}
		else if(x == 4)
		{
			withdraw(accounts);
			if(!promptExit())
			{
				break;
			}
			system("clear");
		}
	} while(x != 5);
	return 0;
}
