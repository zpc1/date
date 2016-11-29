#include <stdio.h>

#include "queue.h"

struct data_st {
	int id;
};

int main(void)
{
	QUEUE *myqueue;
	int id[] = {3, 2, 1, 6, 7, 5, 9};
	int i;

	myqueue = init_queue(sizeof(struct data_st));
	
	for (i = 0; i < sizeof(id)/sizeof(*id); i++) {
		in_queue(myqueue, id+i);
	}
	
	while (!empty_queue(myqueue)) {
		out_queue(myqueue, &i);
		printf("%d ", i);
	}
	printf("\n");

	destroy_queue(myqueue);
	return 0;
}
