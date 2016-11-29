#include <stdlib.h>
#include <string.h>

#include "queue.h"

QUEUE *init_queue(void)
{
	QUEUE * me;	

	me = malloc(sizeof(QUEUE));
	if (NULL == me) {
		return NULL;
	}
	me->base = malloc(sizeof(queuetype_t) * QUEUEMAX);
	me->front = me->rear = 0;
	memset(me->base, 0x00, sizeof(queuetype_t) * QUEUEMAX);

	return me;
}

int enqueue(QUEUE *ptr, queuetype_t data)
{
	if (full_queue(ptr)) {
		return -1;
	}	
	(ptr->base)[ptr->rear] = data;
	ptr->rear =  (ptr->rear+1) % QUEUEMAX;
	
	return 0;
}

int dequeue(QUEUE *ptr, queuetype_t *data)
{
	if (empty_queue(ptr)) {
		return -1;
	}

	*data = (ptr->base)[ptr->front];
	ptr->front = (ptr->front+1) % QUEUEMAX;

	return 0;
}

int empty_queue(QUEUE *ptr)
{
	return ptr->front == ptr->rear;
}

int full_queue(QUEUE *ptr)
{
	return (ptr->rear+1) % QUEUEMAX == ptr->front;
}

void traval_queue(QUEUE *ptr, print_t op)
{
	int i;

	for(i = ptr->front; i != ptr->rear; i = (i+1)%QUEUEMAX) {
		op(ptr->base+i);
	}	
}

void destroy_queue(QUEUE *ptr)
{
	free(ptr->base);
	free(ptr);
}

