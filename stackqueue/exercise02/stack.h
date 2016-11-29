#ifndef SEQ_STACK_H
#define SEQ_STACK_H

#define STACKMAX 30

typedef int datatype_t;

typedef struct stack_st {
	datatype_t stack[STACKMAX];
	int top;
}SEQSTACK;

SEQSTACK *init_stack(void);

int push_stack(SEQSTACK *stack, datatype_t data);

int pop_stack(SEQSTACK *stack, datatype_t *data);

int empty_stack(SEQSTACK *stack);

int full_stack(SEQSTACK *stack);

int get_stacknum(SEQSTACK *);

void destroy_stack(SEQSTACK *ptr);

#endif
