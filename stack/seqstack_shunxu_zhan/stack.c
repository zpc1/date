#include <stdlib.h>
#include <string.h>

#include "stack.h"

SEQSTACK *init_stack(void)
{
	SEQSTACK *mystack;

	mystack = malloc(sizeof(SEQSTACK));
	if (NULL == mystack) {
		return NULL;
	}	
	memset(mystack->stack, 0x00, sizeof(datatype_t)*STACKMAX);
	mystack->top = 0;

	return mystack;
}

int full_stack(SEQSTACK *ptr)
{
	return ptr->top==STACKMAX;
}

int push_stack(SEQSTACK *ptr, datatype_t data)
{
	if (full_stack(ptr)) {
		return -1;
	}
	ptr->stack[(ptr->top)++] = data;

	return 0;
}

int empty_stack(SEQSTACK *ptr)
{
	return ptr->top == 0;
}

int pop_stack(SEQSTACK *ptr, datatype_t *data)
{
	if (empty_stack(ptr)) {
		return -1;
	}

	*data = ptr->stack[--(ptr->top)];

	return 0;
}

void destroy_stack(SEQSTACK *ptr)
{
	free(ptr);
}

