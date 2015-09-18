/*Write a program to determine the ranges of char , short , int , and long
variables, both signed and unsigned , by printing appropriate values from standard headers
and by direct computation.*/
#include<stdio.h>
#include<limits.h>
#include<float.h>
main ()
{
	printf("the range between signed character is %d to %d \n",SCHAR_MIN,SCHAR_MAX );
	printf("the range between signed integer is %d to %d\n",INT_MIN,INT_MAX);
	printf("the range between signed short is %d to %d\n",SHRT_MIN,SHRT_MAX);
//	printf("the range between signed long is %d to %d",LONG_MIN,LONG_MAX);
	printf("the range between unsigned charecter is 0 to %d\n",UCHAR_MAX);
	printf("the range between unsigned integer is 0 to %d\n",UINT_MAX); 
}
