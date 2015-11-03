#include<stdio.h>
#include<ctype.h>
struct key {
	char *word;
	int count;
	}keytab[] = {
		"auto", 0,
		"break", 0,
		"case", 0,
		"char", 0,
		"const", 0,
		"continue", 0,
		"default", 0,
		"unsigned", 0,
		"void", 0,
		"volatile", 0,
		"while", 0
	};
#define nkey 11
#define MAX 1000
int binarysearch(char *, struct key*,int );
int getcode(char *word,int lim);
main()
{
	char word[MAX];
	int n,i;
	while(getcode(word,MAX) != EOF)
//		printf("%s \n ",word);
		if (isalpha(word[0]))
			if((n =binarysearch(word,keytab,nkey)) >0){
	
				keytab[n].count++;
	}
	for(i = 0 ; i <= nkey; i++)
		if(keytab[i].count > 0)
			printf("%d \t %s \n",keytab[i].count,keytab[i].word );
	return 0;
}
int getch(void);
void ungetch(int c);
int getcode(char *word,int lim)
{
	int c,i,d;
	char *w = word;
	while(isspace(c = getch()))
		;
	if(c != EOF )
		*w++ = c;
/*	if(isalpha(c) || c == '_' || c == '#')
		for( ;--lim > 0;w++)
			if(!isalnum(*w = getch() || *w != '_')){
				ungetch(*w);
				break;
			}*/
	 /*if( c == '"' ){
		for( ;--lim >0; w++){
		//	if((*w = getch()) == '\\')
		//		*w++ = getch();
			 if(!isalnum(*w =getch()) || *w == c){
				ungetch(*w);
				break;
			}
		*w++ = '\0';
		return word[0];
		}
	}*/
	if(c == '/' && (d =getch()) == '*'){
		*w++ = d;
		for( ;--lim>0;w++){
			if((*w =getch()) == d && (*w++ = getch()) == c){
                   		 ungetch(c);
				*w++ = '\0';
				 return word[0];
			}
		}
	}
	else if( c == '"'){
		for( ;--lim > 0; w++){
			if((*w = getch()) == c){
				ungetch(c);
				*w++ = '\0';
				return word[0];
			}
		}
	}
	else if( c == '/' && (d =getch()) == '/'){
		*w++ = d;
		for( ; --lim >0; w++){
			if((*w = getch()) == '\n' || *w == EOF){
				ungetch(c);
				*w++ = '\0';
				return word[0];
			}
		}
	}
			
	if(!isalpha(c)){
		*w = '\0';
	  	return c;
	}
	for( ; --lim >0 ;w++ ){
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;	
		}
	}
	*w++ = '\0';
	return word[0];
}
char buf[MAX];
int bufp = 0;
int getch(void)
{
	return (bufp >0)? buf[--bufp]:getchar();
}
void ungetch(int c)
{
 	if(bufp >= MAX)
		printf("buffer get limit\n");
	else
		buf[bufp++] = c;
}
int binarysearch(char *word,struct key tab[], int n)
{
	int mid,low = 0,high,cond;
	high = n-1;
	while(high >= low){
		mid = (low +high)/2;
		if((cond = strcmp(word,tab[mid].word))< 0)
			high = mid-1;
		else if(cond > 0)
			low = mid+1;
		else if(cond == 0)
			return mid;
	}
	return -1;
}


