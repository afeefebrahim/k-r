#include<stdio.h>
#include<ctype.h>
int getint(int *pn);
int getch(void);
void ungetch(int c);
#define SIZE 10
int main (void)
{
    int n, r, array[SIZE],i;
    for( i = 0; i < SIZE; i++)
    {
        array[i] = 0;
        //printf("array[%d] = %d\n", i, array[i]);
    }
    while(n < SIZE)
    {
        if ((r =getint(&array[n])) == 0) {
	        getch();
		n += 1;
        }
        if (r == EOF) {
	    array[n++] = '\0';	
            continue;
		
        }
    }
    for( i = 0; i < SIZE; i++)
   	 printf("array[%d] = %d\n", i, array[i]);

    return 0;
}
int getint(int *pn)
{
	int c,sign,temp;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
		}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
		temp = c;
		while(!isdigit(c= getch())){
			if(c !=EOF){
				ungetch(c);
			}
			ungetch(temp);
			return temp;
		}
	}
		//c =  getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;

	if (c != EOF)
		ungetch(c);
	return c;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
 return (bufp > 0)? buf[--bufp]:getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many charecter \n");
	else
		buf[++bufp] = c;

}

	
