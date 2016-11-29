#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE	32

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
	printf("%d\n",s->id);
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
		printf("    %d",level);
	print_s(&root->data);
	draw_(root->l,level+1);	
}
void draw(struct node_st *root)
{
	draw_(root,0);	
}

balance_(struct node_st *root,int level)
{
	left = left_();
	right = right_();
	if(left == right){
		break;		
	}else if(left > right){
	
	}else{
		
	}
}
void balance(struct node_st *root)
{
	balance(root,0)
}
int main()
{
	struct node_st *tree = NULL;	
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


