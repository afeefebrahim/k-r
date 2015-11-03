struct tnode{
	char *word;
	int line_no[20];
	int ind;
	struct tnode *left;
	struct tnode *right;
};
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
struct tnode *addtree(struct tnode *,char *,int);
int getword(char *w,int lim,int *);
void treeprint(struct tnode *);
main()
{
	int i = 1;
	char word[MAX];
	struct tnode *root;
	root = NULL;
	while(getword(word,MAX,&i) > 0){
//		printf("%s %d \n",word ,i);
		if (isalpha(word[0]))
			root = addtree(root,word,i);
	}
	treeprint(root);
	return 0;
}
int getch(void);
void ungetch(int c);
int getword(char *word,int lim,int *i)
{
	int c;
	char *w = word;
	while (isspace(c = getch()))
		;
	if(c != EOF)
		*w++ = c;
	if(!isspace(c)){
		for( ;--lim > 0 ;w++)
			if(isspace(*w = getch()) || *w == EOF ){
				if(*w == '\n')
					(*i)++;
				ungetch(*w);
				break;
			}
	}else{
		*w = '\0';
		return c;
	}
	*w++ = '\0';
	return word[0];
}
char buf[MAX];
int bufp =0;
int getch(void)
{
	return (bufp >0) ? buf[--bufp] :getchar();
}
void ungetch(int c)
{
	if(bufp > MAX)
		printf("buffer get limit \n");
	else
		buf[bufp++] = c;
}
struct tnode *talloc(void);
char *my_strdup(char *w);
struct tnode *addtree(struct tnode *p,char *w,int i)
{
	int cond,n;
	if(p == NULL){
		p = talloc();
		p->word = my_strdup(w);
		p->ind = 0;
		p->line_no[p->ind++] = i; 
		p->left =p->right = NULL;
	}else if((cond = strcmp(w,p->word)) == 0){
	//	printf("%s %d \n",p->word,i);
	        p->line_no[p->ind++] = i;
		}
	else if(cond < 0)
		p->left = addtree(p->left,w,i);
	else
		p->right = addtree(p->right,w,i);
	return p;
}
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}
char *my_strdup(char *w)
{
	char *p;
	p = (char *) malloc(strlen(w)+1);
	if(p != NULL)
		strcpy(p,w);
	return p;
}	
void treeprint(struct tnode *root)	
{
	int i;
	if(root != NULL){
		treeprint(root->left);
		printf("%s \n",root->word);
		for(i = 0; i < 20; i++)
			printf("%d",root->line_no[i]);
		printf("\n");
		treeprint(root->right);
	}
}
