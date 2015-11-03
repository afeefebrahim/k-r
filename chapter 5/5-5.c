/*Write versions of the library functions strncpy , strncat , and strncmp , which operate on at most the first n characters of their argument strings.*/
#include<stdio.h>
void my_strncpy(char *s,char *t,int n);
void my_strncat(char *s,char *t,int n);
int my_strncmp(char *s,char *t, int n);
#define MAX 100
main()
{
	int n = 4,i;
	char s[MAX] = "hello world";
	char t[MAX] = "hello";
//	my_strncpy(&s[0],&t[0],n);
	my_strncat(&s[0],&t[0],n);
	for(i=0; s[i] != '\0';i++)
		printf("%c",s[i]);
	printf("\n");
	printf("%d \n",my_strncmp(&s[0],&t[0],n));
}
void my_strncpy(char *s,char *t ,int n)
{
	int i;
 	for(i = 0; i <= n; i++,s++,t++)
		*s = *t;
	
}
void my_strncat(char *s,char *t,int n)
{
	int i;
	while(*s != '\0')
		s++;
	for(i=0; i <= n; i++,s++,t++)
		*s = *t;
	s++;
	*s = '\0';	
}
int my_strncmp(char *s,char *t,int n)
{

	for(; (*s == *t); s++,t++)
		if((*t == '\0') && (--n <= 0));
			return 0;
	return *s - *t;
}	
