#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_list_size(t_list *begin_list)
{
	size_t	count;
	printf(GRN_COL"Using ft_list_size for args list begin: %p\n"RST_COL, begin_list);
	count = ft_list_size(begin_list);
	printf("\tafter calling ft_list_size, size is %zu\n", count);
	return (0);
}

int		test_list_size_examples()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;

	test_list_size(NULL);

	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	test_list_size(NULL);

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	test_list_size(l);
	printf(GRN_COL"\nClear the list with one node"RST_COL"\n");
	// ft_list_remove_front(&l, NULL);
	ft_list_remove_if(&l, NULL, ft_always_equal, NULL);	
	test_list_size(l);

	printf(GRN_COL"\nCreate a list with %d nodes"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %d", i);
		content = strdup(buf);
		ft_list_push_front(&l, content);
	}
	test_list_size(l);
	// for (i = 0; i < number; i++)
	// 	ft_list_remove_front(&l, free);
	ft_list_remove_if(&l, NULL, ft_always_equal, free);	
	printf(GRN_COL"\nClear the list with %d nodes"RST_COL"\n", number);
	test_list_size(l);
	return	(0);

}
