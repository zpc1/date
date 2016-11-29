#include <stdio.h>

struct node_st {
	struct node_st *prev;
	struct node_st *next;
	char arr[0];
};

int main(void)
{
	printf("sizeof(struct node_st) = %d\n", sizeof(struct node_st));
	struct node_st *p;

	p = malloc(sizeof(struct node_st) + 10);
	printf("p..............%p\n", p);
	printf("p->arr.........%p\n", p->arr);

	return 0;
}
