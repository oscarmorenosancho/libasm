#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>

int		test_list_sort(t_list **begin_list, int (*cmp)())
{
	printf(GRN_COL"Using ft_list_sort for args list begin: %p cmp: %p\n"RST_COL, begin_list, cmp);
	ft_list_sort(begin_list, cmp);
	printf("\tafter calling ft_list_sort\n");
	if (begin_list)
		print_list(*begin_list);
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
	test_list_sort(&l, ft_greater);

	printf(GRN_COL"\nClear the list with one node"RST_COL"\n");
	ft_list_remove_if(&l, NULL, ft_always_equal, NULL);	
	test_list_sort(&l, ft_greater);

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
	// ft_list_remove_if(&l, NULL, ft_always_equal, free);	
	// print_list(l);

	return	(0);

}