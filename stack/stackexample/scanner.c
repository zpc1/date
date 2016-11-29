#include <stdio.h>

#include "stack.h"

static int isleft(char ch)
{
	return (ch=='{'||ch=='('||ch=='['||ch=='<');
}

static int isright(char ch)
{
	return (ch=='}'||ch==')'||ch==']'||ch=='>');
}

static int is_match(char a, char b)
{
	int ret;

	switch(a) {
		case '{':
			ret = (b =='}');
			break;
		case '<':
			ret = (b =='>');
			break;
		case '(':
			ret = (b ==')');
			break;
		case '[':
			ret = (b ==']');
			break;
		default:
			ret = 0;
	}

	return ret;
}

static int scanner(const char *ptr)
{
	STACK *stack = init_stack(sizeof(char));
	char c;
	
	while (*ptr) {
		if (isleft(*ptr)) {
			push_stack(stack, ptr);
		} else if (isright(*ptr) && !is_empty(stack)) {
			pop_stack(stack, &c);
			if (!is_match(c, *ptr)) {
				break;
			}
		} else if (isright(*ptr) && is_empty(stack)){
			break;
		}
		ptr++;	
	}
	
	if (*ptr == '\0' && is_empty(stack)) {
		destroy_stack(stack);
		return 1;
	}
	destroy_stack(stack);
	return 0;
}

int main(void)
{
	char code[] = "hello<good> {a<fter(noon)[void]}";

	if (scanner(code)) {
		printf("the string :%s is valued\n", code);
	} else {
		printf("the string :%s is invalued\n", code);
	}

	return 0;
}
