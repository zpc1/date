#include <stdlib.h>
#include <string.h>

#include <darr.h>

DARR *init_head_darr(int size)
{
	DARR *p = NULL;

	p = malloc(sizeof(DARR));
	if (NULL == p) {
		return NULL;
	}	

	p->arr = NULL;
	p->size = size;
	p->num = 0;

	return p;
}

int insert_darr(DARR *ptr, const void *data)
{
	char *tmp = NULL;

	tmp = realloc(ptr -> arr, ptr->size * (ptr->num+1));
//	tmp = malloc(ptr->size * (ptr->num+1));
	if (NULL == tmp) {
		return -1;
	}
	memcpy(tmp, ptr->arr, ptr->size * ptr->num);
	memcpy(tmp+ptr->num * ptr->size, data, ptr->size);

//	free(ptr->arr);
	ptr->arr = tmp;

	(ptr->num) ++;

	return 0;
}

int delete_darr(DARR *ptr, const void *key, key_cmp_t cmp)
{
	int i;
	char *tmp = NULL;	

	for (i = 0; i < ptr->num; i++) {
		if (cmp(key, ptr->arr+i*ptr->size) == 0) {
			break;
		}
	}
	if (i == ptr->num) {
		return -1;
	}
	
	memmove(ptr->arr+i*ptr->size, ptr->arr+(i+1)*ptr->size,\
			(ptr->num-i-1)*ptr->size);
	ptr->num--;

	tmp = malloc(ptr->num * ptr->size);
	if (NULL == tmp) {
		return -1;
	}
	memcpy(tmp, ptr->arr, ptr->num * ptr->size);
	free(ptr->arr);
	ptr->arr = tmp;

	return 0;
}

int search_darr(DARR *ptr, const void *key, key_cmp_t cmp, void *data)
{
	int i;

	for (i = 0; i < ptr->num; i++) {
		if (cmp(key, ptr->arr+i*ptr->size) == 0) {
			break;
		}
	}
	if (i == ptr->num) {
		return -1;
	}
	memcpy(data, ptr->arr+i*ptr->size, ptr->size);

	return 0;
}

void traval_darr(DARR *ptr, print_t op)
{
	int i;

	for (i = 0; i < ptr->num; i++) {
		op(ptr->arr + i * ptr->size);
	}
}

void destroy_darr(DARR *ptr) 
{
	free(ptr->arr);
	free(ptr);
}

