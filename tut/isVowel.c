#include<stdio.h>

int isVowel(char c)
{
    int x = (int)c;
    
    if(x == 65 || x == 69 || x == 73 || x == 79 || x == 85)
    {
        return 0;
    }

    x += (65 - 97);

    if(x == 65 || x == 69 || x == 73 || x == 79 || x == 85)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

