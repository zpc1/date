#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NR_ARR		26
#define DESC_SIZE	128
#define KEY_SIZE	128
#define BUFSIZE		256

struct node_st
{
	struct node_st *ch[NR_ARR];
	char desc[DESC_SIZE];
};

int get_word(FILE *fp,char *key,char *desc)
{
	int i;
	char buf[BUFSIZE];
	char *cur;
	char *retp;

	retp = fgets(buf,BUFSIZE,fp);
	if(retp == NULL)
		return -1;

	for(cur = buf,i = 0 ; i < KEY_SIZE && *cur != ':'; i++,cur++)
		key[i] = *cur;
	key[i] = '\0';

	for(cur++,i = 0 ; i < DESC_SIZE && *cur != '\n'; i++,cur++)
		desc[i] = *cur;
	desc[i] = '\0';
	return 0;
}

struct node_st *newnode()
{
	int i;
	struct node_st *node;

	node = malloc(sizeof(*node));
	if(node == NULL)
		return NULL;

	node->desc[0] = '\0';
	for(i = 0 ; i < NR_ARR; i++)
		node->ch[i] = NULL;

	return node;
}

int insert(struct node_st **root,char *key,char *desc)
{

	if(*root == NULL)
	{
		*root = newnode();
		if(*root == NULL)
			return -1;	
	}

	if(*key == '\0')
	{
		strncpy((*root)->desc,desc,DESC_SIZE);
		return 0;	
	}
	return insert((*root)->ch + *key-'a',key+1,desc);
}

char *find(struct node_st *root,char *key)
{

	if(root == NULL)
		return NULL;

	if(*key == '\0')
	{	
		if(root->desc[0] == '\0')
			return NULL;
		return root->desc;
	}
	return find(root->ch[*key-'a'],key+1);
}

int main(int argc,char **argv)
{
	char key[KEY_SIZE];
	char desc[DESC_SIZE];
	FILE *fp;
	struct node_st *tree = NULL;

	if(argc < 2)
	{
		fprintf(stderr,"Usage....\n");
		exit(1);
	}
	
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}
	
	while(1)
	{
		if(get_word(fp,key,desc) != 0)
			break;

		insert(&tree,key,desc);
	}

	char *data = "ant";	
	char *retp;
	retp = find(tree,data);	
	if(retp == NULL)
		printf("Can not find!\n");
	else
		puts(retp);

	close(fp);

	exit(0);
}





