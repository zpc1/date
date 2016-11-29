#include<stdio.h>
#include<string.h>
#include"list.h"
#include<stdlib.h>

LIST *init_list(int size)
{
	LIST *list = NULL;
	
	list = malloc(sizeof(list));
	if(NULL == list){
		return NULL;
	}
	list->head.next = &list->head;
	list->size = size;

	return list;
}

status insert_list(LIST *list, const void *data)
{
	struct node_st *node;
	
	node = malloc(sizeof(struct node_st) + list->size);
	if(NULL == node){
		return FAIL;
	}
	memcpy(node->data, data, list->size);
	node->next = list->head.next;
	list->head.next = node;

	return OK;  
}

status delete_list(LIST *list, const void *key, cmp_t op)
{
	struct node_st *cur, *tmp;
	//tmp = &list->head;tmp = tmp->next, 	tmp->next = tmp->next-next;
	for(cur = list->head.next, tmp = &list->head; \
			cur != &list->head; \
			cur = cur->next, tmp = tmp->next){
		if(!op(key, cur->data)){	
			tmp->next = cur->next;
			free(cur->data);
			free(cur);	
		}<F12>c 
	}
	return OK;	
}

void traval_list(LIST *list, traval_t op)
{
	struct node_st *cur;
	for(cur = list->head.next; cur != &list->head; cur = cur->next){
		op(cur->data);
	}
}

void destroy_list(LIST *list)
{
	struct node_st *tmp,*cur;            //        cur = tmp->next,不能写在tmp = cur 之前,是因为第一次判断执行后把tmp,free(tmp)掉了,之后无法找到.
	for(tmp = list->head.next; tmp != &list->head; tmp = cur){
		cur = tmp->next;
		free(tmp);
	}
	free(list);
}




