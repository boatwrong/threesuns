#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "isVowel.h"

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("Too few arguments\n");
        return 1;
    }

	if(argc == 2)
	{
		printf("English to Tut\n");


        int inputLength = strlen(argv[1]);

        char* input = (char*)NULL;

        input = (char*)malloc(sizeof(char) * (inputLength + 1));

        if (input == (char*)NULL)
        {
            printf("ERROR\n");
            return 1;
        }

        strcpy(input, argv[1]);

        printf("In tut: %s\n", input);

        printf("In english: ");
        for(int i = 0; i < strlen(input); i++)
        {
            printf("%c", input[i]);

            if(!(isVowel(input[i]) == 0))
            {
                i+=2;
            }

        }

        printf("\n");
        free(input);
        return 0;
	}
}

