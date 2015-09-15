/*Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop.*/
#include <stdio.h>
#define TABINC 8

main ()
{
	int c, i=1, ns =0;
	
	while ((c = getchar()) != EOF){
		if (c == '\t'){
			ns = 	TABINC - (i-1)%TABINC;
  			while (ns >= 0){
				putchar(' ');
  				++i;
				ns =ns-1;
			}
		}
		else if(c == '\n') {
		     putchar(c);
		     i = 1;
		}
		else{
	 	     putchar(c);
		     ++i;
		}
	}
}
		 
