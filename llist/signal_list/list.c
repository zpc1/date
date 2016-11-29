#include <stdlib.h>
#include <string.h>
#include "list.h"

LIST *init_head(int size)
{
	LIST *list;

	list = malloc(sizeof(LIST));
	if (list == NULL) {
		return NULL;
	}	
	list->head.data = NULL;
	list->head.next = &list->head;
	list->size = size;
	list->num = 0;

	return list;
}

int insert_list(LIST *list, void *data, int way)
{
	struct node_st *new;
	struct node_st *rear;

	new = malloc(sizeof(*new));
	if (NULL == new) {
		return -1;
	}	
	new->data = malloc(list->size);
	if (NULL == new->data) {
		return -1;
	}
	memcpy(new->data, data, list->size);

	if (way == FORWARD) {
		new->next = list->head.next;	
		list->head.next = new;
	} else if (way == BEHIND){
		for (rear = list->head.next; rear->next != &list->head; rear = rear->next);
		new->next = rear->next;
		rear->next = new;	
	} else {
		return -1;
	}
	list->num ++;

	return 0;
}

int delete_list(LIST *list, const void *key, cmp_t op)
{
	struct node_st *cur;
	struct node_st *prev;

	for (cur=list->head.next, prev=&list->head; \
		cur != &list->head; cur = cur->next, prev = prev->next) {
		if (op(key, cur->data) == 0) {
			prev->next = cur->next;
			free(cur->data);
			free(cur);
			list->num --;
			return 0;
		}	
	}

	return -1;
}

void traval_list(LIST *list, print_t op)
{
	struct node_st *tmp;	

	for (tmp = list->head.next; tmp != &list->head; tmp = tmp->next) {
		op(tmp->data);	
	}
}

