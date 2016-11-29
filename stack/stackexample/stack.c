#include <stdlib.h>
#include "stack.h"

STACK *init_stack(int size)
{
	return init_llist(size);
}

int push_stack(STACK *ptr, const void *data)
{
	return insert_llist(ptr, data, FORWARD);
}

static int always(const void *d1, const void *d2)
{
	return 0;
}

int pop_stack(STACK *ptr, void *data)
{
	return fetch_llist(ptr, NULL, always, data);	
}

int is_empty(STACK *ptr)
{
	return ptr->head.next == &ptr->head;	
}

void destroy_stack(STACK *ptr)
{
	destroy_llist(ptr);
}

