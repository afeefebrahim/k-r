/*Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s .*/
#include<stdio.h>
#include<string.h>
void itob (int n, char s[], int b);
void reverse(char s[]);
main()
{
	int n = 13,b = 16;
	char s[30];
	itob(n,s,b);
}
void itob(int n, char s[], int b)
{
	int sign,i = 0,temp,j = 0;
	char r[30];
	if((sign = n) < 0)
		n = -n;
	do {
		temp = n%b;
	  	if (temp <= 9)
			s[i++] = '0'+temp;
		else
			s[i++] = 'a'+(temp-10);
	} while((n /=b) > 0);

	reverse(s);

}
void reverse (char s[])
{
	int i,j = 0;
	char r[30];
	for (i=strlen(s)-1; i >= 0;--i)
		r[j++] = s[i];
	printf("result = %s\n",r);
}
