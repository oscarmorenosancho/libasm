#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static int		test_list_size(t_list *begin_list, int exp_size)
{
	int	count;
	int	res = 0;

	printf(GRN_COL"Using ft_list_size for args list begin: %p\n"RST_COL, begin_list);
	count = ft_list_size(begin_list);
	res = (count != exp_size);
	printf("\tafter calling ft_list_size, size is %d\n", count);
	print_test_result(res);
	return (res);
}

int		test_list_size_act()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;
	int		res = 0;

	print_test_header("ft_list_size");

	res += test_list_size(NULL, 0);

	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	res += test_list_size(NULL, 0);

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	res += test_list_size(l, 1);
	printf(GRN_COL"\nClear the list with one node"RST_COL"\n");
	ft_list_remove_if(&l, NULL, ft_always_equal, NULL);	
	res += test_list_size(l, 0);

	printf(GRN_COL"\nCreate a list with %d nodes"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %d", i);
		content = strdup(buf);
		ft_list_push_front(&l, content);
	}
	res += test_list_size(l, number);
	ft_list_remove_if(&l, NULL, ft_always_equal, free);	
	printf(GRN_COL"\nClear the list with %d nodes"RST_COL"\n", number);
	res += test_list_size(l, 0);
	return	(res);

}
