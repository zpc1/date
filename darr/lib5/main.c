#include <stdio.h>

#include <darr.h>

#define NAMESIZE 32

struct stu_st {
	int id;
	char name[NAMESIZE];
	int ch;
	int english;
};

static void print_arr(const void *data)
{
	const struct stu_st *d = data;

	printf("%-3d%-10s%-3d%d\n", d->id, d->name, d->ch, d->english);
}

int id_cmp(const void *key, const void *data)
{
	const int *k = key;
	const struct stu_st *d = data;

	return *k - d->id;
}

int name_cmp(const void *key, const void *data)
{
	const char *k = key;
	const struct stu_st *d = data;

	return strcmp(k, d->name);
}

int data_cmp(const void *data1, const void *data2)
{
	const struct stu_st *d1 = data1;
	const struct stu_st *d2 = data2;

	return d1->id - d2->id;
}

int main(void)
{
	srand(time(NULL));
	DARR *myarr;
	int id[] = {3, 5, 2, 1, 8, 9};
	struct stu_st tmp;
	int i;
	int del_id;

	myarr = init_sort_darr(sizeof(struct stu_st), id_cmp, data_cmp);
	
	for (i = 0; i < sizeof(id)/sizeof(*id); i++) {
		tmp.id = id[i];
		snprintf(tmp.name, NAMESIZE, "stu%d", id[i]);
		tmp.ch = rand()%100;
		tmp.english = rand()%50 + 50;

		insert_sort_darr(myarr, &tmp);
	}
	traval_darr(myarr, print_arr);
	printf("\n");
	del_id = 2;
	if (search_darr_bin(myarr, &del_id, id_cmp, &tmp) < 0) {
		printf("not found\n");
	} else {
		printf("find it: %s %d\n", tmp.name, tmp.id);
	}
	
	destroy_darr(myarr);
	return 0;
}
