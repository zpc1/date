#ifndef _STACK_H
#define _STACK_H
#include "llist.h"

typedef LLIST STACK;

STACK *init_stack(int size);

int push_stack(STACK *, const void *data);

int pop_stack(STACK *, void *data);

void destroy_stack(STACK *);

int is_empty(STACK *);
#if 0
	is_empty();
	is_full();	
#endif

#endif
