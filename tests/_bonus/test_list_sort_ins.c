#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static int		test_list_sort_ins(t_list **begin_list, char *content, int (*cmp)())
{
	t_list *node;

	if (begin_list)
	{
		node = ft_create_elem(content);
		printf("\tNode created is %p content is: \"%s\"\n", node, (char*)node->data);
		printf("\tsize before insert %d\n", ft_list_size(*begin_list));

		printf(GRN_COL"\tTest to ins an element sorted on list by ft_list_sort_ins"RST_COL"\n");
		ft_list_sort_ins(begin_list, node, cmp);
		printf("\tsize after insert %d\n", ft_list_size(*begin_list));

	}
	else
		printf(ORG_COL"\tNo list provided"RED_COL"\n");
	return	(0);
}


int		test_list_sort_ins_act()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;
	int		off[] = {5, 7, 1, 4, 6, 3, 0, 9, 8, 2};

	print_test_header("ft_list_sort_ins");

	printf(GRN_COL"Test to insert an element to NULL list"RST_COL"\n");
	test_list_sort_ins(NULL, "inserted", ft_greater);

	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	print_list(l);
	test_list_sort_ins(&l, "inserted", ft_greater);
	print_list(l);
	printf(GRN_COL"\nClear list"RST_COL"\n");
	ft_list_remove_if(&l, NULL, ft_always_equal, NULL);

	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	print_list(l);
	printf(GRN_COL"\nCreate a list with %d node"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %05d", off[i] * 10 + i);
		content = strdup(buf);
		test_list_sort_ins(&l, content, ft_greater);
	}
	print_list(l);
	printf(GRN_COL"\nClear list"RST_COL"\n");
	ft_list_remove_if(&l, NULL, ft_always_equal, free);
	return	(0);
}
