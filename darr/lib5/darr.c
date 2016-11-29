#include <stdlib.h>
#include <string.h>

#include <darr.h>

struct darr_st {
	char *arr;
	int size;
	int num;
	key_cmp_t key;
	key_cmp_t diff;
};

DARR *init_sort_darr(int size, key_cmp_t key, key_cmp_t diff)
{
	struct darr_st *p = NULL;

	p = malloc(sizeof(*p));
	//if error
	p->arr = NULL;
	p->size = size;
	p->num = 0;
	p->key = key;
	p->diff = diff;

	return p;
}

static int bsearch_near(struct darr_st *ptr, const void *data)
{
	int ret;
	int low, high, mid = 0;
	low = 0;
	high = ptr->num - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		ret = ptr->diff(ptr->arr+mid*ptr->size, data);
		if (ret == 0) {
			break;
		}
		if (ret < 0) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return mid;
}

int insert_sort_darr(DARR *p, const void *data)
{
	struct darr_st *ptr = p;
	int ind;

	ptr->arr = realloc(ptr->arr, (ptr->num+1)*ptr->size);
	//if error

	if (ptr->num == 0 || ptr->diff == NULL) {
		ind = 0;
	} else {
		ind = bsearch_near(ptr, data);
		if (ptr->diff(ptr->arr+ind*ptr->size, data) < 0) {
			ind ++;
		}
	}
	
	memmove(ptr->arr+(ind+1)*ptr->size, ptr->arr+ind*ptr->size,\
		   	ptr->size*(ptr->num - ind));
	memcpy(ptr->arr+ind*ptr->size, data, ptr->size);
	
	ptr->num++;

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

