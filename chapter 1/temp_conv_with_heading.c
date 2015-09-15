/*the temperature conversion program to print a heading above the table.*/
#include <stdio.h>
main()
{
float fahr, celsius;
float lower, upper, step;
lower = 0;
upper = 300;
step = 20;
fahr = lower;
printf("\t  TEMPERATURE CONVERTION \n");
while (fahr <= upper) 
{
celsius = 5/9 * (fahr-32) ;
printf("%f\t%f\n", fahr, celsius);
fahr = fahr + step;
}
}
