#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_list_pop_front(t_list **begin_list, int free_cont)
{
	t_list *node;

	printf(GRN_COL"Test to pop an element from a list by ft_list_pop_front"RST_COL"\n");
	node = ft_list_pop_front(begin_list);
	printf("\tNode popped by ft_list_pop_front content is: %p\n", node);
	if (node)
	{
		printf("\tnode content is: \"%s\"\n", (char *)node->data);
		if (free_cont)
			ft_destroy_elem(node, free);
		else
			ft_destroy_elem(node, NULL);
	}
	return	(0);
}


int		test_list_pop_front_examples()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;

	print_test_header("ft_list_pop_front");

	printf(GRN_COL"Test to pop an element from NULL"RST_COL"\n");
	test_list_pop_front(NULL, 0);

	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	print_list(l);
	test_list_pop_front(&l, 0);
	print_list(l);

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	print_list(l);
	test_list_pop_front(&l, 0);
	print_list(l);

	printf(GRN_COL"\nCreate a list with %d node"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %d", i);
		content = strdup(buf);
		ft_list_push_front(&l, content);
	}
	print_list(l);
	for (i = 0; i < number; i++)
		test_list_pop_front(&l, 1);
	print_list(l);
	return	(0);
}
