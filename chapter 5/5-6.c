#include<stdio.h>
#include<string.h>
int my_getline(char *s,int lim);
int my_atoi(char *s);
void itoa(int num, char *s);
void reverse(char *s);
int strindex(char *s,char *p);
int getop(char *s);
#define MAX 100
char pattern[MAX] = "ould"; 
main()
{
	char s[MAX];
	int lim = 100,num = 234,i,f =0;
//	printf ("%d \n",my_getline(&s[0],lim));	
//	printf ("%d \n",my_atoi(&s[0]));
	itoa( num, s);
	for(i = 0; s[i] != '\0'; i++ )
		printf("%c ", s[i]);
	printf("\n");
	while((my_getline(&s[0],lim)) > 0){
		if(strindex(&s[0],&pattern[0])){
			for(i=0; s[i] != '\0'; i++){
				printf("%c",s[i]);
				
			}
			f++;
		}
	}
//	printf("\n %d \n", strindex(&s[0],&pattern[0]));
	getop(s);
	for (i =0; s[i] != '\0'; i++)
		printf("%c",s[i]);
	printf("\n");
}
int my_getline(char *s,int lim)
{
	int c,i;
	for(i = 0; (i <= lim)&&(c = getchar()) != EOF && c != '\n'; i++)
		*s++ = c;
	if(c == '\n'){
		*s++ = c;
		i++;
	}
  	*s++ = '\0';
	return i;
}
int my_atoi(char *s)
{
	int n =0;
	for( ;*s >= '0' && *s <= '9'; s++)
		n = 10 * n +(*s - '0');
	return n; 
}
void itoa(int num, char *s)
{
	char temp[MAX];
	char *bs = s;
	int sign,i;
	if ((sign = num) < 0)
		num = -num;
	do {
		*s++ = num %10 + '0';
	}while((num /=10) >0 );
	if (sign < 0)
		*s++ = '-';
	*s++ = '\0';	
/*	for(i=0 ; bs != &temp[0]; bs--,i++)
		printf("%c \n", temp[i]);
	for(i =strlen(temp) -1  ;i >= 0 ;i-- )
		*s++ = temp[i];
	*s++ = '\0';*/
	reverse(bs);
	
}
void reverse(char *s)
{
	int c;
	char *t;
	for(t = s+strlen(s)-1; t >= s; s++,t--){
		c = *s;
		*s = *t;
		*t = c;
	}
}	
int strindex(char *s,char *p)
{
	int i;
	char *bss = s;
	char *bp;
	char *bs;
	for ( ; *s != '\0'; s++){
		for(bs = s,bp = p;(*p != '\0')&&(*bs == *bp); bs++,bp++)
			;
		if( (bp > p) && (*bp == '\0'))
			return s -bss;
	}
		return -1;
}
int getch(void);
void ungetch(int c);
int getop(char *s)
{
	char *bs = s;
	int c;
	while((*s = c = getch()) == ' ' || c == '\t')
		;
	*s++ = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	s = bs;
	if (isdigit(c))
		*s++ = c;
		while(isdigit(*s++ = c = getch()))
			;
	if(c == '.')
		while(isdigit(*s++ = c = getch()))
			;
	*s = '\0';
	if(c != EOF)
		ungetch(c);
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
	return (bufp > 0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

