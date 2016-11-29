#include <stdio.h>

#include "stack.h"

int main(void)
{
	int number;
	int push;
	STACK *stack;

	printf("which to change:");
	scanf("%d", &number);

	stack = init_stack(sizeof(int));

	while (number) {
		push = number % 2;
		push_stack(stack, &push);
		number /= 2;
	}
	while (!is_empty(stack)) {
		pop_stack(stack, &push);
		printf("%d", push);
	}
	printf("\n");

	destroy_stack(stack);

	return 0;
}

