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
		while (cur)
		{
			print_list_node(cur);
			cur = cur->next;
		}
	}
	else
		printf(ORG_COL"List is Empty"RST_COL"\n");
}