#include <stdio.h>
int lower(int n);
main()
{
	char n = 'd';
//	printf("enter a lower_case letter ");
//	scanf("%c ", &n);
	printf("upper case character is %c \n",lower(n));
}
int lower (int n)
{
	return ('a' <= n|| 'z' >= n )?'A'+( n -'a') : n;
}
