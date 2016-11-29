#ifndef LLIST_H
#define LLIST_H

typedef void (*traval_t)(const void *);
typedef int (*cmp_t) (const void *, const void *);

typedef int status;
#define OK 		0
#define FAIL 	1

enum insert_em{FORWARD = 1, BEHIND};

struct node_st_ {
	void *data;
	struct node_st_ *prev;
	struct node_st_ *next;
};

typedef struct {
	struct node_st_ head;
	int size;
}LLIST;

LLIST *init_llist(int size);

status insert_llist(LLIST *, const void *data, enum insert_em way);

status delete_llist(LLIST *, const void *key, cmp_t op);

void * search_llist(LLIST *, const void *key, cmp_t op);

status fetch_llist(LLIST *, const void *key, cmp_t op, void *node);

void traval_llist(LLIST *, traval_t op);

void destroy_llist(LLIST *list);
//homework

void revers_llist(LLIST **list);

void revers_r(LLIST *);

int get_nodes(LLIST *);

#endif
