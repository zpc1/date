#include <stdio.h>

#include "stack.h"

#define ERROR -100

static STACK *mys;

static int is_number (char tmp)
{
	return (tmp >= '0' && tmp <= '9');
}

static int is_operator (char tmp)
{
	return (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/');
}

static int real_cacu(int a, char op, int b)
{
	int ret;

	switch (op) {
		case '+':
			ret = a + b;
			break;
		case '-':
			ret = a - b;
			break;
		case '*':
			ret = a * b;
			break;
		case '/':
			ret = a / b;
			break;
		default:
			return ERROR;
	}	

	return ret;
}

static int caculate(const char *ptr)
{
	int left, right;
	int result;
	int tmp;
	
	mys = init_stack(sizeof(int));

	while (*ptr) {
		if (is_number(*ptr)) {
			tmp = *ptr-'0';
			push_stack(mys, &tmp);
		}else if (is_operator(*ptr)) {
			if (!is_empty(mys)) {
				pop_stack(mys, &right); 
			} else {
				break;
			}
			if (!is_empty(mys)) {
				pop_stack(mys, &left);
			} else {
				break;
			}
			result = real_cacu(left, *ptr, right);
			push_stack(mys, &result);
		} else {
			printf("invalued express\n");
			return ERROR;
		}
	
		ptr++;
	}
	if (!is_empty(mys)) {
		pop_stack(mys, &result);
		if (*ptr=='\0' && is_empty(mys)) {
			return result;
		}
	}
	return ERROR;
}

int main(void)
{
	printf("result is %d\n", caculate("923*+82/-"));
	
	destroy_stack(mys);

	return 0;
}
