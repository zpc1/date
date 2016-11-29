#include <stdio.h>

#include "list.h"

struct data_st {
	int id;
	char name[32];
};

void print(const void *data)
{
	const struct data_st *d = data;
	printf("%-4d%s\n", d->id, d->name);
}

int id_cmp(const void *key, const void *data)
{
	int *k = (int *)key;
	const struct data_st *d = data;

	return *k - d->id;
}

int main(void)
{
	LIST *mylist;
	int id[] = {5,7,8,1,2,6,9,10};
	struct data_st tmp;
	int i;
		
	mylist = init_head(sizeof(struct data_st));

	for (i = 0; i < sizeof(id)/sizeof(*id); i++) {
		tmp.id = id[i];
		snprintf(tmp.name, 32, "congming%d", id[i]);
		insert_list(mylist, &tmp, BEHIND);	
	}
	traval_list(mylist, print);
	printf("\n");
	i = 10;
	delete_list(mylist, &i, id_cmp);
	traval_list(mylist, print);

	return 0;
}
