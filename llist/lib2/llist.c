#include <stdlib.h>
#include <string.h>
#include "llist.h"

LLIST *init_llist(int size)
{
	LLIST *list = NULL;	

	list = malloc(sizeof(*list));
	if (NULL == list) {
		return NULL;
	}
	list->head.prev = list->head.next = &list->head;
	list->size = size;

	return list;
}

status insert_llist(LLIST *list, const void *data, enum insert_em way)
{
	struct node_st *node;

	node = malloc(sizeof(struct node_st) + list->size);
	if (NULL == node) {
		return FAIL;
	}
	memcpy(node->data, data, list->size);

	if (way == FORWARD) {
		node->prev = &list->head;
		node->next = list->head.next;	
	} else {
		node->prev = list->head.prev;
		node->next = &list->head;
	}
	node->prev->next = node;
	node->next->prev = node;

	return OK;
}
void *search_llist(LLIST *list,const void *key, cmp_t op)
{
	struct node_st *cur;
#if 0

	for(cur=list->head.next;cur!=&list->head;cur=cur->next)
	{
		if(!op(key,cur->data))
			break;
	}
	if (cur == &list->head) {
		return NULL;
	}
	return cur->data;
#endif
	cur = list->head.next;
	while (op(key, cur->data)) {
		cur = cur->next;
		if (cur == &list->head) {
			return NULL;
		}
	}
	return cur->data;
}
int delete_llist(LLIST *list, const void *key, cmp_t op)
{
	struct node_st *cur;

	for (cur = list->head.next; cur != &list->head; cur= cur->next){
		if (!op(key, cur->data)) {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			cur->prev = cur->next = NULL;
			free(cur);

			return OK;
		}
	}

	return FAIL;
}

void traval_llist(LLIST *list, traval_t op)
{
	struct node_st *cur;

	for (cur = list->head.next; cur != &list->head; cur = cur->next) {
		op(cur->data);
	}	

}

status fetch_llist(LLIST *list, const void *key, cmp_t op, void *node)
{
	struct node_st *cur;
	
	for (cur = list->head.next; cur != &list->head; cur = cur->next) {
		if (!op(key, cur->data)) {
			memcpy(node, cur->data, list->size);
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			free(cur);
			return OK;
		}
	}

	return FAIL;
}

void destroy_llist(LLIST *list)
{
	struct node_st *tmp, *cur;

	for (tmp = list->head.next; tmp != &list->head; tmp = cur) {
		cur = tmp->next;
		free(tmp);
	}

	free(list);
}
