#include <stdio.h>
#include "stack.h"

int main(void)
{
	int tmp;
	int container[] = {7,3,2,'-',5,'*','+'};
	int i, ret;
	int data;
	char z1 = '-', z2 = '*', z3 = '+';
	int shu1,shu2,sum;
	STACK *mystack;

	mystack = init_stack(sizeof(int));

	for (i = 6; i >= 0; i--) {
		if(container[i] == z1){
			shu2 = pop_stack(mystack, &data);
			shu1 = pop_stack(mystack, &data);
			sum = 
		}

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
