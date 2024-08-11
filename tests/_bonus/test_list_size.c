#include <stdio.h>
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
	test_list_size(NULL);
	return (0);
}

