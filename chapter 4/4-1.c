/*Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s , or -1 if there is none.*/
#include<stdio.h>
int strindex(char s[], char t[]);
main()
{
	
	char s[1000] = "afhsajvb sdalfhabvaaashfbasbghdag asdsa";
	char t[10] = "aaa";
	printf("right most index of t = %d \n",strindex(s,t));
}
int strindex(char s[], char t[])
{
	int i ,j ,result = -1,k;
	for ( i=0; s[i] != '\0'; ++i){
	       for (k = i,j = 0; t[j] != '\0' && t[j] == s[k]; ++k,++j)
			;
		if (j > 0 && t[j] =='\0' )
			result = i;
	}
	return result;
}

