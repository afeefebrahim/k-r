/*program to count blanks, tabs, and newlines*/
#include <stdio.h>

main()
{
 	int c,new,tab,blank;
        new = 0;
        tab = 0;
        blank =0;
	while((c = getchar()) != EOF)
	{
		if (c =='\n')
		 	++new;
		
		if (c == '\t')
		
			++tab;
		
		if (c == ' ')
		
  			++blank;
		
	}
        printf("\tnum of newline= %d \n \t num of tabs = %d \n \t num of blanks = %d\n",new,tab,blank);
}
