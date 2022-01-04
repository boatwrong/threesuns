#include<stdio.h>

int isVowel(char c)
{
    if((((int)c > 90 && (int)c < 97)) || (int)c < 65 || (int)c > 122)
    {
        printf("is a charachter\n");
        return 0;
    }
    return 1;
}

