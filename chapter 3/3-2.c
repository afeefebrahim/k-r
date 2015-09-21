/*Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s .*/
#include<stdio.h>
void escape( char s[], char t[]);
main()
{
	char s[20] = " afeef	ebrahim  ";
	char t[20] ;
	escape(s,t);
}
void escape(char s[], char t[])
{
	int i,j=0;
	for (i = 0; s[i] != '\0'; ++i){
		switch(s[i]){
			case '\n':
				t[++j] = '\\';
				t[++j] = 'n';
				break;
			
			case '\t':
				t[++j] = '\\';
				t[++j] = 't';
				break;
			
			default:
				t[++j] = s[i];
					
				break;
			
		}
	}
	printf("resultant string is %s \n",t);
	
}	

