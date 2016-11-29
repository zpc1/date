#include <stdio.h>

#include "stack.h"

int main(void)
{
	srand (time(NULL));
	int i, ret = 1;
	SEQSTACK *mys;
	int tmp;

	mys = init_stack();

	for (i = 0; i < 15; i++) {
		tmp = rand()%20;
		printf("%d ", tmp);
		push_stack(mys, tmp);
	}
	printf("\n");
	while (1) {
		ret = pop_stack(mys, &i);
		if (ret == -1) {
			break;
		}
		printf("%d ", i);
	}
	printf("\n");

	destroy_stack(mys);

	return 0;
}
