#include <stdio.h>
#include "stack.h"

int main(void)
{
	int num = 6;
	int yu,sh;
	STACK *mystack;
	int ret,data;

	mystack = init_stack(sizeof(int));

	while( !num ){
		yu = num % 2;
		push_stack(mystack, &yu);			
		num /= 2;
	}
	
	ret = OK;
	while (!is_empty(mystack)) {
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
