#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct data_st {
	int id;
	char name[32];
	struct list_head node;
};

int main(void)
{
	LIST_HEAD(list);
	struct data_st *tmp;
	struct data_st *data;
	struct list_head *pos;

	printf("struct data..%d\n",sizeof(struct data_st));
	printf("tmp..........%d\n",sizeof(tmp));
	printf("tmp->id......%d\n",sizeof(tmp->id));
	printf("tmp->name....%d\n",sizeof(tmp->name));
	printf("&tmp.........%d\n",sizeof(&tmp));
	printf("tmp->node....%d\n",sizeof(tmp->node));
	printf("&tmp->node...%p\n",tmp->node);
//	struct list_head *ttt = { NULL, NULL, NULL};

	int id[] = {3,2,6,8,9,1};
	int i;

	for (i = 0; i < sizeof(id) / sizeof(*id); i++) {
		tmp = malloc(sizeof(struct data_st));
		if (NULL == tmp) {
			return -1;
		}
		tmp->id = id[i];
		snprintf(tmp->name, 32, "stu%d", id[i]);
		list_add(&tmp->node, &list);
	}
	
	list_for_each(pos, &list) {
		data = list_entry(pos, struct data_st, node);
		printf("%d %s\n", data->id, data->name);
	}	

	return 0;
}

vgscan