/*Verify that the expression getchar() != EOF is 0 or 1.*/
#include <stdio.h>

main()
{
	int c,n;
        while((c = getchar()) != EOF)
	{
 		n = getchar() != EOF;
		printf("\t %d \n", n);
	}

}    

