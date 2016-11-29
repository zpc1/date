#include <stdio.h>
#include "stack.h"

int main(void)
{
	int tmp;
	int container[] = {1,2,3,4,5,6,7,8,9,10};
	int i, ret;
	int data;
	STACK *mystack;

	mystack = init_stack(sizeof(int));

	for (i = 0; i < 10; i++) {
		push_stack(mystack, container+i);
	}
	ret = OK;
	while (1) {
		ret = pop_stack(mystack, &data);
		if (ret == FAIL) {
			break;
		}
		printf("%d ", data);
	}
	printf("\n");
	
	destroy_stack(mystack);

	return 0;
}
