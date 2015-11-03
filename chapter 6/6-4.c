/*Write a program that prints the distinct words in its input sorted into decreasing order of frequency of occurrence.*/
struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
int ptr = 0;
struct tnode *list[MAX];
void store(struct tnode *root);
struct tnode *addtree(struct tnode *,char *);
int getword(char *,int lim);
void sort (void);
main()
{
	char word[MAX];
	struct tnode *root;
	root = NULL;
	int i;
	while(getword(word,MAX) > 0){
//		printf("%s \n",word);
		if(isalpha(word[0]))
			root = addtree(root,word);
	}
	store(root);
	sort();	
	for(i = ptr-1; i > 0;i--)
		printf("%s %d \n",list[i]->word,list[i]->count);

}
void ungetch(int c);
int getch(void);
int getword(char *word,int lim)
{
	int c;
	char *w = word;
	while(isspace(c = getch()))
		;
	if(c != EOF)
		*w++ = c;
	if(!isspace(c)){
		for( ;--lim > 0; w++)
			if(isspace(*w = getch()) || *w == EOF){
				ungetch(*w);
				break;
			}
	}else {
		*w = '\0';
		return c;
	}
	*w++ = '\0';
	return word[0];
}
char buf[MAX];
int bufp = 0;
int getch(void)
{
	return (bufp > 0)?buf[--bufp]:getchar();
}
void ungetch (int c)
{
	if(bufp > MAX)
		printf("buffer limit exist\n");
	else
		buf[bufp++] = c;
}
struct tnode *talloc(void);
char *my_strdup(char *);
struct tnode *addtree(struct tnode *p,char *w)
{
	int cond;
	if(p == NULL){
		p = talloc();
		p->word = my_strdup(w);
		p->count =1;
		p->left = p->right = NULL;
	} else if((cond = strcmp(w,p->word)) == 0)
		p->count++;
	else if(cond > 0)
		p->right = addtree(p->right,w);
	else
		p->left = addtree(p->left,w);
	return p;
}
#include<stdlib.h>	
struct tnode *talloc(void)
{
	return (struct tnode*) malloc(sizeof(struct tnode));
}
char *my_strdup(char *s)
{
	char *p;
	p = (char *) malloc(strlen(s)+1);
	if(p != NULL)
		strcpy(p,s);
	return p;
}
void store(struct tnode *p)
{
	if(p != NULL){
		store(p->left);
		if (ptr < MAX)
			list[ptr++] = p;
		store(p->right);
	}
}	
void sort (void)
{
	int i,j,gap;
	int temp;
	for (gap = ptr/2; gap >0; gap /= 2)
		for(i = gap; i < ptr; i++)
			for(j = i-gap; j >= 0 && (list[j]->count)>(list[j+gap]->count); j-=gap){
				temp = list[j]->count;
				list[j]->count = list[j+gap]->count;
				list[j+gap]->count = temp;
			}
}
