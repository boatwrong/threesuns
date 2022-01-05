#include<stdio.h>

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
    int totals[maxTotal - 1];
    int totalsInstances[maxTotal - 1];
    int d1[numSides];
    int d2[numSides];
    int probabilityDenominator = numSides * numSides;

    for(int i = 0; i <= maxTotal; i++)
    {
        int j=2;
        totals[i] = j;
        j++;
    }

    for(int i = 0; i <= maxTotal; i++)
    {
        totalsInstances[i] = 0;
    }

    
    for(int i = 1; i <= numSides; i++)
    {
        d1[i] = i;
        d2[i] = i;
    }

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

    
    return 0;
}

