#include <stdio.h>

#include "stack.h"
#include "queue.h"

static int isNumber(char ch)
{
	return ch >= '0' && ch <= '9';
}

static int isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

static int isLeft(char ch)
{
	return ch == '(';
}

static int isRight(char ch)
{
	return ch == ')';
}

static int prioriry(char ch)
{
	int flag = 0;

	if (ch == '+' || ch == '-') {
		flag = 1;
	} 
	if (ch == '*' || ch == '/') {
		flag = 2;
	}
	return flag;
}

int transform(const char *ptr)
{
	QUEUE *myque;
	STACK *mystk;
	char tmp;

	myque = init_queue(sizeof(char));
	if (NULL == myque) {
		return -1;
	}
	mystk = init_stack(sizeof(char));
	if (NULL == mystk) {
		return -1;
	}

	while (*ptr) {
		if (isNumber(*ptr)) {
			in_queue(myque, ptr);
		} else if (isOperator(*ptr)) {
			while (1) {
				if (!get_top(mystk, &tmp)) {
					if (prioriry(*ptr) <= prioriry(tmp)) {
						pop_stack(mystk, &tmp);
						in_queue(myque, &tmp);			
					} else {
						break;
					}	
				}else {
					break;
				}
			}
			push_stack(mystk, ptr);
		} else if (isLeft(*ptr)) {
			push_stack(mystk, ptr);
		} else if (isRight(*ptr)) {
			while (1) {
				pop_stack(mystk, &tmp);
				if (is_empty(mystk) && !isLeft(tmp)) {
					return -1;
				}
				if (isLeft(tmp))
					break;
				in_queue(myque, &tmp);
			}
		} else {
			return -1;
		}
		ptr++;
	}

	while (!is_empty(mystk)) {
		pop_stack(mystk, &tmp);
		in_queue(myque, &tmp);	
	}

	while (!empty_queue(myque)) {
		out_queue(myque, &tmp);
		printf("%c", tmp);
	}
	printf("\n");

	destroy_stack(mystk);
	destroy_queue(myque);
	return 0;
}

int main(void)
{
	char str[] = "4+(3+5)*8-2";

	transform(str);

	return 0;
}
