/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y , leaving the other bits unchanged.*/
#include<stdio.h>
unsigned setbits(unsigned x,int p, int n,unsigned y);
main()
{
	unsigned x,y;
	int p,n;
	printf("enter the x,position,nbits,y");
	scanf("%u \t %d \t %d \t %u",&x ,&p,&n,&y);
	printf("resultand binary number is %u \n",setbits(x,p,n,y));
}
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & (~(~(~0<<n))<<(p+1-n))) | (y & (~(~0<<n)<<(p+1-n)));

}
