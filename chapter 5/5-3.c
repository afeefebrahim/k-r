/*Write a pointer version of the function strcat that we showed in strcat(s,t) copies the string t to the end of s .*/
#include<stdio.h>
#include<string.h>
void strcat1(char *s, char *t);
#define MAX 100
main()
{
	int i;
 	char s[MAX] = "afeef ";
	char t[MAX] = "ebrahim";
	strcat1(&s[0],&t[0]);
	for(i=0; s[i] != '\0';i++)
		printf("%c", s[i]);
	printf("\n");
	return 0;
}

void strcat1(char *s,char *t)
{
	while(*s != '\0')
		s++;
	for( ; (*s = *t) != '\0'; s++,t++)
		;
	*s++ = '\0';
}

