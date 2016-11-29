#include <stdio.h>

#include "llist.h"

#define NAMESIZE 32

struct info_t {
	char name[NAMESIZE];
	char sex;
	int qq;
};

void print_info (const void *data)
{
	const struct info_t *d = data;

	printf("%-10s%-5c%d\n", d->name, d->sex, d->qq);
}

int chr_cmp(const void *key, const void *data)
{
	const char *k = key;
	const struct info_t *d = data;

	return *k-d->sex;	
}

int str_cmp(const void *key, const void *data)
{
	const char *k = key;
	const struct info_t *d = data;

	return strcmp(k, d->name);
}

int main(void)
{
	srand(time(NULL));
	LLIST *mylist;
	int i;
	struct info_t tmp, *search;
	int num;
	char sexvar;

	mylist = init_llist(sizeof(struct info_t));
	//if error	
	
	for (i = 0; i < 10; i++) {
		snprintf(tmp.name , NAMESIZE, "stu%c", rand()%26+'a');
		tmp.sex = (rand() % 2) == 0 ? 'f' : 'm';
		tmp.qq = rand()%10000 + 100000;

		insert_llist(mylist, &tmp, FORWARD);
	}
	traval_llist(mylist, print_info);

#if 0
	printf("\n");
	sexvar = 'm';
	delete_llist(mylist, &sexvar, chr_cmp);
	traval_llist(mylist, print_info);

	search = search_llist(mylist, "stus", str_cmp);
	if (search == NULL) {
		printf("not find\n");
	} else {
		printf("find it: %s %c %d\n", search->name, search->sex, search->qq);
	}
	printf("\n");
	sexvar = 'f';
	if (fetch_llist(mylist, &sexvar, chr_cmp, &tmp) != 0) {
		printf("invalued...\n");
	} else {
		printf("fetch it: %s %c %d\n", tmp.name, tmp.sex, tmp.qq);
	}
#endif
	printf("********************************\n\n");
//	revers_llist(&mylist);
	revers_r(mylist);
	traval_llist(mylist, print_info);
	printf("it have %d nodes\n", get_nodes(mylist));

	destroy_llist(mylist);	
	return 0;
}
