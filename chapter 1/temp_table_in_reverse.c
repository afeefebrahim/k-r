/*Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0.*/
#include <stdio.h>
main()
{
int faren;
printf("\t FARENHEAT-DEGREE CONVERTION IN REVERSE ORDER \n"); 
for(faren = 300; faren >= 0; faren = faren-20)
 {
  printf ("\t %d \t %f \n", faren, 5.0/9.0*(faren-32));
 }
} 
