#include <stdio.h>

#include "stack.h"
#include "queue.h"

#define BOLL_NR 27

int check_queue(QUEUE *ptr)
{
	int i;

	for (i = ptr->front; i != (ptr->rear-1+QUEUEMAX)%QUEUEMAX; i = (i+1)%QUEUEMAX) {
		if (ptr->base[i] > ptr->base[(i+1)%QUEUEMAX]) {
			return 0;
		}
	}	
	return 1;
}

void print_queue(const void *data)
{
	const int *d = data;
	printf("%d ", *d);
}

int main(void)
{
	QUEUE *myqueue;
	SEQSTACK *onemin;
	SEQSTACK *fivemin;
	SEQSTACK *onehour;
	int i;
	int deq, tmp;
	int time_cnt = 0;

	myqueue = init_queue();
	if (NULL == myqueue) {
		return -1;
	}
	onemin = init_stack();
	//if error
	fivemin = init_stack();
	//if error
	onehour = init_stack();
	//if error
	
	for (i = 1; i <= BOLL_NR; i++) {
		enqueue(myqueue, i);
	}
	traval_queue(myqueue, print_queue);	
	printf("\n");

	while (1) {
		dequeue(myqueue, &deq);	
		time_cnt ++;
		if (get_stacknum(onemin) < 4) {
			push_stack(onemin, deq);
		} else {
			while (!empty_stack(onemin)) {
				pop_stack(onemin, &tmp);
				enqueue(myqueue, tmp);
			}
			if (get_stacknum(fivemin) < 11) {
				push_stack(fivemin, deq);
			} else {
				while (!empty_stack(fivemin)) {
					pop_stack(fivemin, &tmp);
					enqueue(myqueue, tmp);
				}
				if (get_stacknum(onehour) < 11) {
					push_stack(onehour, deq);
				} else {
					while (!empty_stack(onehour)) {
						pop_stack(onehour, &tmp);
						enqueue(myqueue, tmp);
					}
					enqueue(myqueue, deq);	
					if (check_queue(myqueue)) {
						break;
					}
				}
			}
		}
	}

	traval_queue(myqueue, print_queue);	
	printf("\n");
	printf("time = %d\n", time_cnt/60/24);

	destroy_stack(onemin);
	destroy_stack(fivemin);
	destroy_stack(onehour);
	destroy_queue(myqueue);
	return 0;
}
