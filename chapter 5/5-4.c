/*Write the function strend(s,t) , which returns 1 if the string t occurs at the end of the string s , and zero otherwise.*/
#include<stdio.h>
#include<string.h>
int mystrend(char *s, char *t);
#define MAX 100
main()
{
	int n;
	char s[MAX] = "being";
	char t[MAX] = "ng";
	n = mystrend(s,t);
	printf("%d\n", n);
}
int mystrend(char *s,char *t)
{
	char *bs = s;
	char *bt = t;
	while(*s != '\0')
		s++;
	while(*t != '\0')
		t++;
	
	for (; *s = *t; s--,t--)
		if ((s == bs) ||(t == bt))
			break;
	if((*t == *s) && (t == bt) )
		return 1;
	else
		return 0;
}
