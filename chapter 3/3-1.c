#include<stdio.h>
int binsearch(int x, int v[] , int n);

main()
{
	int x = 6, n = 10;
	int v[10] = {2,3,4,5,6,7,8,9,10,11};
	printf("binsearch result = %d", binsearch(x,v,n));
}
int binsearch(int x, int v[], int n)
{
	int mid,low,high;
	low = 0;
	high = n-1;
	mid = (low + high)/2;
	while( high > low && x != v[mid]){
		if (v[mid] > high)
			high = high+1;
		else
			low = low+1;
	}
	if (v[mid] == x)
		return x;
	else
		return -1;
}
	
