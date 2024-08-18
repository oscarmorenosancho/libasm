#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

void	print_list_node(t_list *node)
{
	if (node)
		printf(GRN_COL"Node: %p, content: \"%s\" next: %p"RST_COL"\n", node, (char*)node->data, node->next);
	else
		printf(RED_COL"Node is NULL"RST_COL"\n");
}

void	print_list(t_list *list)
{
	t_list *cur = list;

	if (list)
	{
		printf(CYN_COL"\nFront list here\n"RST_COL);
		while (cur)
		{
			print_list_node(cur);
			cur = cur->next;
		}
		printf(CYN_COL"List finish here"RST_COL"\n\n");
	}
	else
		printf(ORG_COL"List is Empty"RST_COL"\n\n");
}

void	print_binary(long value)
{
	int i;
	int len = sizeof (long) * 8;
	char buf[len + 1];
	long cur;

	cur = value;
	for (i = 0; i < len; i++)
	{
		buf[len - i - 1] = (cur & 1)? '1' : '0';
		cur >>= 1; 
	}
	buf[len] = 0;
	printf("%s", buf);
}

void	print_binary_int(int value)
{
	int i;
	int len = sizeof (int) * 8;
	char buf[len + 1];
	long cur;

	cur = value;
	for (i = 0; i < len; i++)
	{
		buf[len - i - 1] = (cur & 1)? '1' : '0';
		cur >>= 1; 
	}
	buf[len] = 0;
	printf("%s", buf);
}
