#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE	32


static struct node_st *tree = NULL;	

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
};

struct node_st
{
	struct score_st data;
	struct node_st *l,*r;
};

void print_s(struct score_st *s)
{
//	printf("%d %s %d\n",s->id,s->name,s->math);
	printf("%d \n",s->id);
}

int insert(struct node_st **root,struct score_st *data)
{
	struct node_st *node;	

	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;

		node->data = *data;
		node->l = NULL;
		node->r = NULL;
		
		*root = node;
		return 0;
	}	

	if(data->id <= (*root)->data.id)
		return insert(&(*root)->l,data);
	return insert(&(*root)->r,data);
}

struct score_st *find(struct node_st *root,int myid)
{
	if(root == NULL)
		return NULL;	

	if(myid == root->data.id)
		return &root->data;
	
	if(myid < root->data.id)
		return find(root->l,myid);
	return find(root->r,myid);
}

void draw_(struct node_st *root,int level)
{
	int i;

	if(root == NULL)
		return ;
	
	draw_(root->r,level+1);
	for(i = 0 ; i < level; i++)	
		printf("    ");
	print_s(&root->data);
	draw_(root->l,level+1);	
}

void draw(struct node_st *root)
{
	draw_(root,0);	
	getchar();
}

int get_num(struct node_st *root)
{
	if(root == NULL)
		return 0;

	return get_num(root->l) + 1 + get_num(root->r);
}

struct node_st *find_min(struct node_st *root)
{
	if(root->l == NULL)
		return root;
	return find_min(root->l);
}

struct node_st *find_max(struct node_st *root)
{
	if(root->r == NULL)
		return root;
	return find_max(root->r);
}

void turn_left(struct node_st **root)
{
	struct node_st *cur = *root;	

	*root = cur->r;
	cur->r = NULL;
	find_min(*root)->l = cur;

	draw(tree);

}

void turn_right(struct node_st **root)
{

	struct node_st *cur = *root;

	*root = cur->l;
	cur->l = NULL;
	find_max(*root)->r = cur;

	draw(tree);
}

void balance(struct node_st **root)
{
	int sub;
	
	if(*root == NULL)
		return ;

	while(1)
	{
		sub = get_num((*root)->l) - get_num((*root)->r);

		if(sub >= -1 && sub <= 1)
			break;

		if(sub < -1)
			turn_left(root);
		else
			turn_right(root);
	}

	balance(&(*root)->l);
	balance(&(*root)->r);

}

void traval(struct node_st *root)
{
	if(*root == NULL)
		return;
		
	traval(root->l);
	traval(root->r);
	print_s(&root->data);
}
int main()
{
	struct score_st tmp,*datap;
	int arr[] = {1,2,3,7,6,5,9,8,4};
	int i;

	for(i = 0 ; i < sizeof(arr)/sizeof(*arr); i++)
	{
		tmp.id = arr[i];
		snprintf(tmp.name,NAMESIZE,"stu%d",tmp.id);
		tmp.math = 100 - arr[i];

		insert(&tree,&tmp);	
	}	


	draw(tree);

	balance(&tree);

	draw(tree);
	traval(tree);

#if 0

	int myid = 19;
	datap = find(tree,myid);
	if(datap == NULL)
		fprintf(stderr,"find() failed.\n");
	else
		print_s(datap);

#endif


	exit(0);
}


