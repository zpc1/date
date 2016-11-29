#ifndef MY_LIST_H
#define MY_LIST_H

#define FORWARD 0
#define BEHIND	1

typedef int (*cmp_t)(const void *key, const void *data);
typedef void (*print_t)(const void *data);

struct node_st {
	void *data;
	struct node_st *next;
};

typedef struct {
	struct node_st head;
	int size;
	int num;
}LIST;

LIST *init_head(int size);

int insert_list(LIST *, void *data, int way);

int delete_list(LIST *, const void *key, cmp_t op);

void traval_list(LIST *, print_t op);

#endif
