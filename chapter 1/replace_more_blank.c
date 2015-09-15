/*a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.*/
#include <stdio.h>

main ()
{
  	int c,flag = 0;
	while((c = getchar()) != EOF){
		
		if (c == ' '){

			if (flag == 0){
				flag = 1;
 				putchar(c);
          			
                                }
 			}
                if (c != ' '){

                         flag = 0;

                         putchar(c);        
 			}
	  }
}
