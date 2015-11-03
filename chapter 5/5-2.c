/*Write getfloat , the floating-point analog of getint*/
#include<stdio.h>
#include<ctype.h>
int getfloat(float *pn);
int getch(void);
void ungetch(int c);
#define SIZE 10
int main (void)
{
    float array[SIZE];
    int n, r,i;
    for( i = 0; i < SIZE; i++)
    {
        array[i] = 0;
        //printf("array[%d] = %d\n", i, array[i]);
    }
    while(n < SIZE)
    {
        if ((r =getfloat(&array[n])) == 0) {
	        getch();
		n += 1;
        }
        if (r == EOF) {
	    array[n++] = '\0';	
            continue;
		
        }
    }
    for( i = 0; i < SIZE; i++)
   	 printf("array[%d] = %f\n", i, array[i]);

    return 0;
}
int getfloat(float *pn)
{
	int c,sign,temp;
	float po;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
		}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c =  getch();
	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
	if(c == '.')
		c = getch();
	for(po = 1.0; isdigit(c); c =getch()){
		*pn = 10.0 * *pn + (c - '0');
		po *=10;
	}
	*pn = (*pn/po)*sign;

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

	
