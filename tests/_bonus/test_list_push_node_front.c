#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_list_push_node_front(t_list **begin_list, t_list *node)
{
	printf(GRN_COL"Using ft_list_push_node_front for args list begin: %p  %p"RST_COL"\n", begin_list, node);
	if (node)
		printf("\tnode content data is: \"%s\"  next points to: %p\n", (char*)node->data, node->next);
	if (begin_list)
	{
		printf("\t list begin points at %p\n", *begin_list);
	}
	else
	{
		printf("\t no list provided\n");
	}
	ft_list_push_node_front(begin_list, node);
	printf("\tafter calling ft_list_push_node_front\n");
	if (begin_list)
	{
		t_list *n1 = *begin_list;
		printf("\tfirst node content data of list is: \"%s\"  next points to: %p\n", (char*)n1->data, n1->next);
		free (n1);
	}
	return (0);
}

int		test_list_push_node_front_examples(void)
{
	t_list *l = NULL;
	t_list *node;

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	print_list(l);

	printf(GRN_COL"\nCreate a node"RST_COL"\n");
	node = ft_create_elem("new static data");
	print_list_node(node);

	printf(GRN_COL"\nPush the node: %p"RST_COL"\n", node);
	ft_list_push_node_front(&l, node);
	print_list(l);
	return (0);
}
