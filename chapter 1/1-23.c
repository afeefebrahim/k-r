/*Write a program to remove all comments from a C program.*/
#include<stdio.h>
void rcommand(int c);
void in_comment(void);
void echo_quote(int c);
main ()
{
	int c,d;
	while ((c = getchar()) != EOF)
		rcommand(c);
}
void rcommand(int c){
	int d,r;
	if (c == '/'){
 		if ((d = getchar()) == '*')
			in_comment();
	  	else if (d == '/'){
			while ((r = getchar()) != '\n' )
				;
			rcommand(d);
		}else{
			putchar(c);
			putchar(d);
		 }
	}
	/*else if (c == '\'' || c == '"')
		echo_quote(int c);*/
 	else
		putchar(c);
}
void in_comment(void){
	int c,d;
	while ( (c = getchar()) != '/' && (d = getchar()) != '*'){
		c = d;
		d = getchar();
	}
}

 
