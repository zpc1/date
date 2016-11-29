#ifndef MY_DARR_H
#define MY_DARR_H

typedef int (*key_cmp_t)(const void *, const void *);
typedef void (*print_t)(const void *);

typedef void DARR;

DARR *init_head_darr(int size);

int insert_darr(DARR *ptr, const void *data);

int delete_darr(DARR *ptr, const void *key, key_cmp_t cmp);

void traval_darr(DARR *ptr, print_t op);

int search_darr(DARR *ptr, const void *key, key_cmp_t cmp, void *data);

void destroy_darr(DARR *);

#endif
