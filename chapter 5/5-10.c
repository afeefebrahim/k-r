#include<stdio.h>
#include<ctype.h>
#define NUMBER 0
int getop(char a[]);
void ungetch(char s);
void push(double );
double pop(void);
#define MAXL 100
main(int argc,char *argv[])

{

	char s[MAXL];
	double op;
	int i =1;
	while(--argc > 0){
		switch(getop(argv[i])){
			case NUMBER:
				push(atoi(argv[i]));
			//	printf("%d",atoi(argv[i]));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				push(pop() - pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op = pop();
				if(op == 0.0)
					printf("the divisor is zero");
				else
					push(pop()/op);
				break;
			default: 
				printf("error : undefined command");
				argc = 1;
				break;
		}
	i++;
	}
	printf("\t %g \n", pop());

}
#define MAX 100
int sp = 0;
double val[MAX];
void push(double f)
{
//	printf("%d \n",sp);
	if (sp < MAX){
		val[sp++] = f;
	
	}else
		printf("error: stack is full out of order");
}
double pop(void)
{
	if(sp >= 0)
		return val[--sp];
	else
		printf("stack is empty");
}
int getch(void);
int getop(char a[])
{
/*	char  s[];
	int i,c;
	if ((s[0] = c = getch()) == " " || c == "\t")
		;
	s[1] = '\0';*/
	if( !isdigit(a[0]) ){
//		printf("%d \n",a[0]);
		return a[0];
	}
/*	i = 0;
	if (isdigit(c))
		while(isdigit(s[i++] = c = getch()))
			;
	if( c == '.')
		while(isdigit(s[i++] = c = getch()))
			;
	s[i++] = '\0';*/
	if (isdigit(a[0])){
//		printf("%d \n",a[0]);
		return NUMBER;
	}
}
char buf[MAX];
int bufp = 0;
int getch(void)
{
	if(bufp >0)
		return buf[--bufp];
}
void ungetch(char s)
{
	if(bufp > MAX)
	 	printf("ungetch: too many characters\n");
	else
		buf[bufp++] = s;
}

	

	

	
	

