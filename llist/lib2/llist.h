#ifndef LLIST_H
#define LLIST_H

typedef void (*traval_t)(const void *);
typedef int (*cmp_t) (const void *, const void *);

typedef int status;
#define OK 		0
#define FAIL 	1

enum insert_em{FORWARD = 1, BEHIND};

struct node_st {
	struct node_st *prev;
	struct node_st *next;
	char data[0];
};

typedef struct {
	struct node_st head;
	int size;
}LLIST;

LLIST *init_llist(int size);

status insert_llist(LLIST *, const void *data, enum insert_em way);

status delete_llist(LLIST *, const void *key, cmp_t op);

void * search_llist(LLIST *, const void *key, cmp_t op);

status fetch_llist(LLIST *, const void *key, cmp_t op, void *node);

void traval_llist(LLIST *, traval_t op);

void destroy_llist(LLIST *list);


#endif
