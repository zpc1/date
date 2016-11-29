#ifndef LIST_H
#define LIST_H

typedef void (*traval_t)(const void *);
typedef int (*cmp_t) (const void *, const void *);
typedef int status;

#define OK 		0
#define FAIL 	1

struct node_st {
	struct node_st *next;
	char data[0];
};
typedef struct {
	struct node_st head;
	int size;
}LIST;

LIST *init_list(int size);

status insert_list(LIST *, const void *data);

status delete_list(LIST *, const void *key, cmp_t op);

void traval_list(LIST *, traval_t op);

void destroy_list(LIST *list);

#endif
