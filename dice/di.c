#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
    const int MIN_TOTAL = 2;
    int  numSides, maxTotal;
    printf("This program will show you the possible totals of rolling two\n");
    printf(" dice of a specific number of sides\n");
    printf("\nPlease enter the number of sides (2-100)\n\n");
    
    scanf("%d", &numSides);

    while(numSides < 2 || numSides > 100)
    {
        printf("Please enter a valid integer between 2 and 100\n");

        scanf("%d", &numSides);
    }

    maxTotal = 2 * numSides;
    int numTotals = maxTotal - 1; 
    int totals[numTotals];
    float totalsInstances[numTotals];
    float actualInstances[numTotals];
    int d1[numSides];
    int d2[numSides];
    int probabilityDenominator = numSides * numSides;
    int z=MIN_TOTAL;
    int numRounds = 36000;

    for(int i = 0; i < numTotals; i++)
    {
        totals[i] = z;
        z++;
    }

    for(int i = 0; i < numTotals; i++)
    {
        actualInstances[i] = 0;
        totalsInstances[i] = 0;
    }


    int sideValue = 1;
    for(int i = 0; i < numSides; i++)
    {
        d1[i] = sideValue;
        d2[i] = sideValue;
        sideValue++;

    }
    printf("\n");


    for(int i = 0; i < maxTotal; i++)
    {
        for(int j = 0; j < numSides; j++)
        {
            for(int k = 0; k < numSides; k++)
            {
                if((d1[j] + d2[k]) == totals[i])
                {
                    totalsInstances[i]++;
                }
            }
        }
    }

    float totalPercentages[maxTotal - 1];
    float actualPercentages[maxTotal - 1];


    srand(time(NULL));
    int num1, num2;
    for(int x = 0; x < numRounds; x++)
    {
        num1 = (rand() % numSides) + 1;
        num2 = (rand() % numSides) + 1;
        // printf("num1: %d, num2: %d\n", num1, num2);
        for(int i = 0; i < maxTotal; i++)
        {
            if((num1 + num2) == totals[i])
            {
                actualInstances[i]++;
            }

        }
    }

    for(int i=0; i < numTotals; i++)
    {
        totalPercentages[i] = (float)totalsInstances[i] / (float)probabilityDenominator;
        actualPercentages[i] = (float)actualInstances[i] / (numRounds);
    }


    printf("Number of sides for dice: %d\n\n", numSides);

    printf("TOTALS  CALC    ACTUAL\n");
    for(int i=0; i < maxTotal - 1; i++)
    {
        printf(" %d\t%05.2f%%\t%05.2f%%\n", totals[i], totalPercentages[i] * 100, actualPercentages[i] * 100);

    }

    return 0;
}

