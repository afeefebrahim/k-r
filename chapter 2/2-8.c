/*Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.*/
#include <stdio.h>
unsigned rightrot (unsigned x, int n);
int count (unsigned x);
main()
{
	int x, n;
	x = 20;
	n = 3;
	printf("rotated  decimal equvalent is %d\n", rightrot(x,n));
}
unsigned rightrot (unsigned x, int n)
{
	int l;
	l = count(x);
	return x >> n | (x & (~(~(1 << (l-n)<<n))) << (l-n)); 	
}
int count (unsigned x)
{
	int count;
	while (x != 1){
		x >>= 1;
		++ count;
	}
	return count;
}

