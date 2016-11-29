#include <stdio.h>

#include "llist.h"

#define HASH_NR 	10
#define NAMESIZE 	32

struct stu_st {
	int id;
	char name[NAMESIZE];
};

LLIST *hash_arr[HASH_NR];

int hash_fun(int key)
{
	return key % HASH_NR;
}

void hash_insert(struct stu_st data)
{
	int ind;

	ind = hash_fun(data.id);
	insert_llist(hash_arr[ind], &data, FORWARD);
}

void print_hash(const void *data)
{
	const struct stu_st *d = data;

	printf("%d %s\n", d->id,d->name);
}

int main(void)
{
	srand(getpid());
	int i;
	struct stu_st tmp;

	for (i = 0; i < HASH_NR; i++) {
		hash_arr[i] = init_llist(sizeof(struct stu_st));
	}

	for (i = 0; i < 100; i++) {
		tmp.id = rand() % 100;	
		snprintf(tmp.name, NAMESIZE, "stu%d", i);

		hash_insert(tmp);
	}
	for (i = 0; i < HASH_NR; i++) {
		printf("the %d list:\n", i+1);
		traval_llist(hash_arr[i], print_hash);
		printf("**********************\n");
	}

	return 0;
}
