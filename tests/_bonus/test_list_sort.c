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
		printf(RED_COL"List is Empty"RST_COL"\n");
}

int		test_list_sort(t_list **begin_list, int (*cmp)())
{
	printf(GRN_COL"Using ft_list_sort for args list begin: %p cmp: %p\n"RST_COL, begin_list, cmp);
	ft_list_sort(begin_list, cmp);
	printf("\tafter calling ft_list_sort\n");
	if (begin_list)
		print_list(*begin_list);
	return (0);
}

static int		always_equal(const char *s1, const char *s2)
{
	(void)s1;
	(void)s2;
	return (0);
}

int		test_list_sort_examples()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;

	(void)buf;
	(void)content;
	(void)number;
	(void)i;

	// printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	// print_list(l);

	// test_list_sort(&l, strcmp);

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	print_list(l);
	test_list_sort(&l, strcmp);

	printf(GRN_COL"\nClear the list with one node"RST_COL"\n");
	ft_list_remove_if(&l, NULL, always_equal, NULL);	
	test_list_sort(&l, strcmp);

	// printf(GRN_COL"\nCreate a list with %d nodes"RST_COL"\n", number);
	// for (i = 0; i < number; i++)
	// {
	// 	sprintf(buf, "%05d", i);
	// 	content = strdup(buf);
	// 	ft_list_push_front(&l, content);
	// 	printf(GRN_COL"\tpush node %p, data:\"%s\", next:%p"RST_COL"\n", l, (char*)l->data, l->next);
	// }
	// print_list(l);
	// test_list_sort(&l, strcmp);

	// printf(GRN_COL"\nClear the list with %d nodes"RST_COL"\n", number);
	// ft_list_remove_if(&l, NULL, always_equal, free);	
	// print_list(l);

	return	(0);

}