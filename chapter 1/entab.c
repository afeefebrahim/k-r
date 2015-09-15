/*Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing.*/
#include <stdio.h>
#define tabinx 8
main()
{
	int c,i,nt = 0,ns = 0;
	for (i = 1; (c = getchar()) !=EOF; ++i ){
		if (c == ' '){
			if ((i % tabinx) != 0)
				++ns;
			else{
				++nt;
				ns = 0;
			}
		}
		else{
			for( ;nt > 0; --nt)
				putchar('\t');
			if (c == '\t') 	
				ns = 0;
			else{
				for ( ;ns > 0; --ns)
					putchar (' ');
			}
			putchar(c);
			if (c == '\n')
				i =1;
			else{
				if (c == '\t')
				    i = i+ (tabinx -(i-1)%tabinx)-1;
			} 
		}
	}
}
