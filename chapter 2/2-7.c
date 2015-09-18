/* function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/
#include<stdio.h>
unsigned invert(unsigned x, int p, int n);
main()
{
	unsigned int x;
	int p,n;
	printf("enter decimal, position,no of bit");
	scanf("%u %d %d\t",&x,&p,&n);
	printf( "the result is :%u\n",invert(x,p,n));
 	
}
unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(1 << n)) <<(p+n-1);
}
	
