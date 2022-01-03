#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		printf("Hello\n");
		printf("%s\n", argv[1]);
		func();

	
	}
}

