#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_list_remove_front(t_list **begin_list, void (*free_fct)(void *))
{
	// t_list *node;
	if (!begin_list)
		printf(GRN_COL"list passed is NULL"RST_COL"\n");
	else if (!(*begin_list))
		printf(GRN_COL"list passed is empty"RST_COL"\n");
	printf(GRN_COL"Using ft_list_remove_front"RST_COL"\n");
	printf(GRN_COL"Test to remove an element from list %p with free_fct %p"RST_COL"\n", begin_list, free_fct);
	if (begin_list)
	{
		t_list	*node = *begin_list;
		printf(GRN_COL"front node in list is %p"RST_COL"\n", node);
		if (node)
			printf(GRN_COL"front node content is \"%s\", next is %p"RST_COL"\n", (char*)node->data, node->next);
	}
	ft_list_remove_front(begin_list, free_fct);
	printf("After calling ft_list_remove_front list %p"RST_COL"\n", begin_list);
	if (begin_list)
	{
		t_list	*node = *begin_list;
		printf(GRN_COL"front node in list is %p"RST_COL"\n", node);
		if (node)
			printf(GRN_COL"front node content is %s, next is %p"RST_COL"\n", (char*)node->data, node->next);
	}

	// printf(GRN_COL"Node popped by ft_list_pop_front content is: %p"RST_COL"\n", node);
	// printf(GRN_COL"node content content is: \"%s\""RST_COL"\n", (char *)node->data);
	return	(0);
}

int		test_list_remove_front_examples()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;

	print_test_header("ft_list_remove_front");

	test_list_remove_front(NULL, NULL);

	printf(GRN_COL"Create an empty list"RST_COL"\n");
	test_list_remove_front(&l, NULL);

	printf(GRN_COL"Create a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	test_list_remove_front(&l, NULL);

	printf(GRN_COL"Create a list with %d nodes"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %d", i);
		content = strdup(buf);
		ft_list_push_front(&l, content);
	}
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %d", i);
		test_list_remove_front(&l, free);
	}
	return	(0);
}