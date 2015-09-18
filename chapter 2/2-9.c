/*n a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x . Explain why. Use this observation to write a faster version of bitcount .*/
#include<stdio.h>
int bitcount(unsigned x);
main()
{
	unsigned int x;
	printf("enter the number\t");
	scanf("%u",&x);
	printf("bitcount = %u \n",bitcount(x));
}
int bitcount(unsigned x)
{
	int count;
	while(x != 0){
		++count;
		x &=(x-1);
	}
	return count;
}
