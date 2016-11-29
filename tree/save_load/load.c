#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct node_st *tree = NULL;	

struct node_st
{
	char data;
	struct node_st *l,*r;
};

void draw_(struct node_st *root,int level)
{
	int i;

	if(root == NULL)
		return ;
	
	draw_(root->r,level+1);
	for(i = 0 ; i < level; i++)	
		printf("    ");
	printf("%c\n",root->data);
	draw_(root->l,level+1);	
}

void draw(struct node_st *root)
{
	draw_(root,0);	
}

struct node_st *load_(FILE *fp)
{
	int ch;
	struct node_st *root;

	ch = fgetc(fp);
	if(ch != '(')
	{
		fprintf(stderr,"read error.\n");
		exit(1);
	}

	ch = fgetc(fp);
	if(ch == ')')
		return NULL;
	
	root = malloc(sizeof(*root));
	if(root == NULL)
		exit(1);
	
	root->data = ch;
	
	root->l = load_(fp);

	root->r = load_(fp);

	ch = fgetc(fp);		// ')'
	
	return root;
}

void load(const char *fname)
{
	FILE *fp;

	fp = fopen(fname,"r");
	if(fp == NULL)
		return ;

	tree = load_(fp);

	fclose(fp);
}


int main(int argc,char **argv)
{
	int i;

	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s <filename>\n",argv[0]);
		exit(1);
	}

	load(argv[1]);

	draw(tree);

	exit(0);
}
