/*Write a program to print the corresponding Celsius to Fahrenheit table.*/
#include <stdio.h>
main()
 {
float degree,faren;
int lower,upper,step;
lower =0;
upper = 300;
step =20;
printf("\t DEGREE TO FARENHEAT CONVERTION \n"); 
while (degree <= upper)
 {
 faren = 9/5 * degree + 32;
 printf("\t %6.2f \t %6.2f \n",degree,faren);
 degree = degree +step;
 }
 }
