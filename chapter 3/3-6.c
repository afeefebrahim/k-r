#include<stdio.h>
#include<string.h>
void itob(int n, char s[], int mw);
void reverse( char s[]);
main()
{
	int n = 234, mw =10;
	char s[20];
	itob(n,s,mw);
}
void itob(int n, char s[], int mw)
{
	int i = 0,sign;
	if ((sign = n) < 0)
		n = -n;
	do{
		s[i++] = (n % 10) + '0';
	}while((n /= 10) > 0 );
	for ( ;i <= mw; ++i)
		s[i] = ' ';
	reverse(s);
}
void reverse(char s[])
{
	int i,j=0;
	char r[20];
	for(i = strlen(s) - 1; i >= 0; --i)
		r[j++] = s[i];
	printf("result = %s \n",r);
}
