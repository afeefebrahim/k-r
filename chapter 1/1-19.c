/*Write a function reverse(s) that reverses the character string s*/
#include <stdio.h>
#define MAX 100
int main(void)
{
	int i =0,c,len;
	char line[MAX];
	while ((c = getchar()) != EOF){
		if (c != '\n'){
			line[i] = c;
			++i;
		}
		else{
			line[i] = '\n';
			line[++i] = '\0';		
			/*printf("%s \n", line);*/
			for (len = i; len >=0; --len) 
				printf ("%c",line[len]);
			i = 0;
		    }

			
	}
	return 0;
}

			
