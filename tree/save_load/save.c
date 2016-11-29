#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct node_st *tree = NULL;	

struct node_st
{
	char data;
	struct node_st *l,*r;
};

int insert(struct node_st **root,int data)
{
	struct node_st *node;	

	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;

		node->data = data;
		node->l = NULL;
		node->r = NULL;
		
		*root = node;
		return 0;
	}	

	if(data <= (*root)->data)
		return insert(&(*root)->l,data);
	return insert(&(*root)->r,data);
}

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

int save_(struct node_st *root,FILE *fp)
{
	
	fputc('(',fp);	

	if(root == NULL)
	{
		fputc(')',fp);
		return 0;
	}

	fputc(root->data,fp);

	save_(root->l,fp);

	save_(root->r,fp);

	fputc(')',fp);

	return 0;
}

void save(struct node_st *root,char *fname)
{
	FILE *fp;

	fp = fopen(fname,"w");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}
	
	save_(root,fp);

	fclose(fp);
}

int main(int argc,char **argv)
{
	char arr[] = "cefadjbh";
	int i;

	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s <filename>\n",argv[0]);
		exit(1);
	}
	
	for(i = 0 ; i < strlen(arr); i++)
	{
		insert(&tree,arr[i]);	
	}	

	draw(tree);

	save(tree,argv[1]);
	
	exit(0);
}


