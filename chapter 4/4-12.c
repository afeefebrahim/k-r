/*write a recursive version of itoa ; that is, convert
an integer into a string by calling a recursive routine.*/
#include<stdio.h>
void itoa( char s[],int num);
void reverse(char []);
#define MAX 100
char s[MAX];
main()
{
	int num = 12356;
/*	printf("enter the number :\t \n");
	scanf("%d \t", &num);*/

	itoa(s,num);
}
int sign ,i =0;
void itoa(char s[],int num)
{
	int j;
	char ds[MAX];
	if((sign = num) < 0)
		num = -num;	
	s[i++] = (num % 10) + '0';
	if((num /=10) >0)
		itoa(s,num);
	else{
		
	/*	for (j=0;  >= strlen(s); i--)
			ds[j++] = s[i];
		ds[j++] = '\0';
		printf("result is =%s",ds);*/
		printf("result is%s\n", s);
		reverse(s);
	}
	
}
#include<string.h>
void reverse(char s[])
{
	char ds[MAX];
	int j = 0;
	if (sign <0)
		ds[j++] = '-';
	for(i =(strlen(s)-1); j < strlen(s);i--)
		ds[j++] = s[i];
	ds[j++] ='\0';
	printf("\nresu = %s\n", ds);
}
