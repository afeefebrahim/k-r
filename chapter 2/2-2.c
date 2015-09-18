/*Write a loop equivalent to the for loop above without using && or || .*/
#include <stdio.h>
#define lim 20
main()
{
	int i = 0,c;
	int flag = 1;
	char s[lim];
	while (flag != 0){
		c = getchar();
		if(i < (lim-1)) 
			flag = 0;
		else if (c  == EOF)
			flag = 0;
		else if (c  == '\n')
			flag = 0;
		else {
			s[i] = c;
			++i;
		}
	}
	printf("the string is %s",s);
}

