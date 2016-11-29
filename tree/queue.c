#include <stdlib.h>

#include "queue.h"

QUEUE *init_queue(int size)
{
	return init_llist(size);
}

int in_queue(QUEUE *ptr, const void *data)
{
	return insert_llist(ptr, data, BEHIND);
}

static int always_ok(const void *k, const void *d)
{
	return 0;
}

int out_queue(QUEUE *ptr, void *data)
{
	return fetch_llist(ptr, NULL, always_ok, data);
}

int empty_queue(QUEUE *ptr)
{
	return !get_nodes(ptr);	
}

void destroy_queue(QUEUE *ptr)
{
	destroy_llist(ptr);
}

