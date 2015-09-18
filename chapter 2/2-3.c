/*Write a function htoi(s) , which converts a string of hexadecimal digits into its equivalent integer value.*/
#include<stdio.h>
#define MAX 10
int  htoi(char s[]);
main()
{
	int r,i;
	char s[MAX];
	for(i = 0; i <= MAX; ++i)
		s[i] =0;
	printf("enter the hexadecimal number:");
	scanf(" %s",s);
	int htoi(char s[]);
//	printf(" \nhex equvalent = %d",r ); 
}
int htoi (char s[MAX])
{
	int i = 0,n =0,  result = 0, flag =1;
	if (s[i] == '0')
		++i;
	if (s[i] == 'x' || s[i] == 'x')
		++i;
	for ( ;flag == 1; ++i ){
		if (s[i] >= '0' && s[i] <= '9')
			n = s[i] -'0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = s[i] - 'a' +10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = s[i] - 'A' +10;
		else if (flag == 1)
			result = result + (n*16);
		else
			flag = 0;
	}
	printf("hex equvalent = %d",result);
	return result;
}
