#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#include "llist.h"

typedef LLIST QUEUE;

QUEUE *init_queue(int size);

int in_queue(QUEUE *, const void *data);

int out_queue(QUEUE *, void *data);

int empty_queue(QUEUE *);

void destroy_queue(QUEUE *);

#endif
