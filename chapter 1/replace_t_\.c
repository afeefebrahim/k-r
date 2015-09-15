/*Write a program to copy its input to its output, replacing each tab by \t , each
backspace by \b , and each backslash by \\ .*/
#include <stdio.h>
main()
{
	int c,flag;
  	while ((c = getchar()) != EOF){
        	if  (c == '\t'){
			putchar('\\');
			putchar('t');
		}
		if (c == '\b'){
			putchar('\\');
 			putchar('b');
		}
		if (c == '\\'){
			putchar('\\');
			putchar('\\');
		}
                if (c != '\t' && c != '\b' && c != '\\')
		      putchar(c);
	}
}
