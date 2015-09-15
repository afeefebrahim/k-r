#include <stdio.h>
int rcommand(int c,int s);
void in command(void);
void check_error();
main()
{
	int c,s[6],i,d[6];
	for (i = 0; i< 6, ++i)
		s[i] = 0;
	while ((c = getchar()) != EOF)
	     d = rcommand(c,s);
	if (d[0] == d[3] && d[1] == d[4] && d[2] == d[5] )
		printf (" no error");
	else
		printf ("error occured");
}
void rcommand(int c, int s){
 	int d,r;
        	
	if (c == '/'){
		if ((d =getchar()) == '*')
			in_command();
		else if (d == '/'){
			while ((r = getchar()) != '\n')
				;
			rcommand(d);
		}
		else{
			if (c == '{')
				++s[0];
			else if (c == '[')
				++s[1];
			else if (c == '(')
				++s[2];
			else if (c == '}')
				++s[3];
			else if (c == ']')
				++s[4];
			else if (c == ')')
				++s[5]
		}
	}
	return s;
}
void in_command(void){
	int c,d;
	while( (c = getchar()) != '/' && (d = getchar()) != '*'){
		c = d;
		d = getchar();
	}
}
