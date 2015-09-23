/*Given the basic framework, it's straightforward to extend the calculator. Add the
modulus (%) operator and provisions for negative numbers.*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100
#define number '0'
int getop( char s[]);
void push(double f);
double pop( void);
main()
{
	double op2;
 	char s[MAX] ;
	int c;
	while((c = getop(s)) != EOF){
	
		switch(c){
			case '+':
				push(pop()+pop());
				break;
			case number:
				push(atof(s));
				break;
			case '*':
				push(pop()*pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2= pop();
				if (op2 != 0.0)
					push(pop()/op2);
				else
				        printf("error: zero divisor\n");
					break;
/*			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(),op2));
				else
					printf("error: zero divisor\n");
				break;*/
			case '\n':
				printf("\t %g \n" ,pop());
				break;
			default:
				printf("invalid entry\n");
				break;
			}
	}
}
double val[MAX];
int sp = 0;

void push(double f)
{
	printf("num = %g \n", f);
	if (sp < MAX)
		val[sp++] = f;
	
	else
		printf("error: stack full, can't push %g\n", f);
}
double pop(void)
{
	if(sp > 0)
		return val[sp--];
		
	else
		printf("error: stack empty\n");
}

#include <ctype.h>
int getch(void);
void ungetch(int c);
int getop(char s[])
{
	int i,c;
	while ((s[0] = c = getch()) == ' '|| c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	

	if ( isdigit(c))
		while(isdigit(s[++i] = c= getch()))
			;
	if (c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if( c != EOF )
		ungetch(c);
	return number;
	
}
char buf[MAX];
int bufp = 0;

int getch(void) 
{
	return (bufp > 0)? buf[bufp--]:getchar();
}

void ungetch(int c)
{
	if (bufp >= MAX)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
			
