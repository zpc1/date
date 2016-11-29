#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#define QUEUEMAX 30 

typedef void (*print_t)(const void *);
typedef int queuetype_t;

typedef struct queue_st {
	queuetype_t *base;
	int front;
	int rear;
}QUEUE;

QUEUE *init_queue(void);

int enqueue(QUEUE *, queuetype_t data);

int dequeue(QUEUE *, queuetype_t *data);

int empty_queue(QUEUE *);

int full_queue(QUEUE *);

void traval_queue(QUEUE *, print_t );

void destroy_queue(QUEUE *);

#endif
