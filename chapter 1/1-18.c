/*Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.*/
#include <stdio.h>
#define temp 30
main()
{
// as you wish
	int c,i = 0;
	char line[temp];
	while ((c =getchar()) != EOF){
		if (c != '\n' ){
			if (c == '\t' || c == ' ')
/* hasdfjadkfdsahads;
bfdsahlfsalfbas;*/				;
			
			else{
				line[i] = c;
				++i;
			    }
		}
		else{
			line[i] = '\0';
		printf("%s \n", line);
		}
	}
}
