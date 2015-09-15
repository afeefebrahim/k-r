#include <stdio.h>
main()
{
	int c,i,wordlen[15];
        for (i = 0; i <= 15; ++i)
		wordlen[i] = 0;
	while ((c = getchar()) != EOF){
                if (c == ' ' || c == '\t' || c =='\n'){
                     while 
		  	for (i = 0; i <= 15; ++i){
				while ((c = getchar()) && c ==' ' && c == '\t' && c == '\n'){
				++wordlen[i+0]; 
				}
			}
		  }
		else{
			while((c = getchar()) && c != ' ' && c != '\t' && c != '\n')
			;
		    
		
		}
	}
	printf("histogram of words\n");
	for (i =0; i <= 15; ++i)
		printf("%d \n", wordlen[i]);
}
