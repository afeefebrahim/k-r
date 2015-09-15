#include <stdio.h>
float farenheat(int c);
main()
{
	int i;

	for (i=0; i<=300; i = i+20){
 		printf("\t degree: %d \tfarenheat: %f \n" ,i,farenheat(i));
		}
return 0;
}
float farenheat(int c)
{
	float f;
	f = (9/5*c)+32;
	return f;
}	
