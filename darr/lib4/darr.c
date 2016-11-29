#include <stdlib.h>
#include <string.h>

#include <darr.h>

struct darr_st {
	char *arr;
	int size;
	int num;
};

DARR *init_head_darr(int size)
{
	struct darr_st *p = NULL;

	p = malloc(sizeof(DARR));
	if (NULL == p) {
		return NULL;
	}	

	p->arr = NULL;
	p->size = size;
	p->num = 0;

	return p;
}

int insert_darr(DARR *p, const void *data)
{
	struct darr_st *ptr = p;
	char *tmp = NULL;

	tmp = malloc(ptr->size * (ptr->num+1));
	if (NULL == tmp) {
		return -1;
	}
	memcpy(tmp, ptr->arr, ptr->size * ptr->num);
	memcpy(tmp+ptr->num * ptr->size, data, ptr->size);

	free(ptr->arr);
	ptr->arr = tmp;

	(ptr->num) ++;

	return 0;
}

int delete_darr(DARR *p, const void *key, key_cmp_t cmp)
{
	struct darr_st *ptr = p;
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

int search_darr(DARR *p, const void *key, key_cmp_t cmp, void *data)
{
	struct darr_st *ptr = p;
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

int set_sort(DARR *p, key_cmp_t cmp)
{
	struct darr_st *ptr = p;
	qsort(ptr->arr, ptr->num, ptr->size, cmp);	
}

int search_darr_bin(DARR *p, const void *key, key_cmp_t cmp, void *data)
{
	struct darr_st *ptr = p;	
	char *tmp;
	tmp = bsearch(key, ptr->arr, ptr->num, ptr->size, cmp);
	if (tmp == NULL) {
		return -1;
	}
	memcpy(data, tmp, ptr->size);
	return 0;
}

void traval_darr(DARR *p, print_t op)
{
	struct darr_st *ptr = p;
	int i;

	for (i = 0; i < ptr->num; i++) {
		op(ptr->arr + i * ptr->size);
	}
}

void destroy_darr(DARR *p) 
{
	struct darr_st *ptr = p;
	free(ptr->arr);
	free(ptr);
}

