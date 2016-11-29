#include<stdio.h>
#include"list.h"

#define MAX 32

struct info_t {
	char name[MAX];
	char sex;
	int qq;
};

void print_info (const void *data)
{
	const struct info_t *d = data;
	printf("%-10s%-5c%d\n", d->name, d->sex, d->qq);
}
int chr_cmp(const void *key, const void *date)
{
	const char *k = key;
	const struct info_t *d = date;

	return strcmp(k, d->name);
}

int main(void)
{
	srand(time(NULL));
	LIST *mylist;
	int i;
	struct info_t tmp;
	char sex;

	mylist = init_list(sizeof(struct info_t));
	if(NULL == mylist){
		return FAIL;
	}
	for (i = 0; i < 10; i++) {
		snprintf(tmp.name , MAX, "stu%c", rand()%26+'a');
		tmp.sex = (rand() % 2) == 0 ? 'm' : 'w';
		tmp.qq = rand()%10000 + 100000;
		insert_list(mylist, &tmp);
	}

	traval_list(mylist, print_info);

	printf("\n");
	sex = 'm';
 	delete_list(mylist, &sex, chr_cmp);
	traval_list(mylist, print_info);

	destroy_list(mylist);





	return 0;
}

