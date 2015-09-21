/*Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2 . Allow for letters of either case
and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z*/
#include<stdio.h>
void expand(char s1[], char s2[]);
main()
{
	char s1[20] ="a-z";
	char s2[50];
	expand ( s1, s2);
}
void expand(char s1[], char s2[])
{
	int i,j=0;
	char c;
	for (i=0; s1[i] != '\0';++i){
		if (s1[i] == '-'){
			c = s1[--i];
			++i;
			++i;
			while(c != s1[i]){
				s2[j++] = ++c;
			}
			++i;
		}
	s2[j++] = s1[i];	
	}
	s2[++j] = '\0';
	printf("resultant string is %s", s2);
}
