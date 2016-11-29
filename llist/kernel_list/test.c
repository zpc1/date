#include <stdio.h>

struct node_st {
	struct node_st *p;
	struct node_st *n;	
};

struct te_st {
	int a;
	char b;
	struct node_st node;
	int c;
};

int main(void)
{
	struct te_st test;
	printf("test....%p\n", &test);
	printf("&test.node...%p\n", &test.node);

	printf("%d\n", (size_t)&((struct te_st *)0)->node);

	return 0;
}
