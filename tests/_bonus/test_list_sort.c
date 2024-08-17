#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>

static int		off[] = {5, 7, 1, 4, 6, 3, 0, 9, 8, 2};

static int		test_list_sort(t_list **begin_list, int (*cmp)())
{
	int	sort_ret;

	sort_ret = 1;
	printf(GRN_COL"Using ft_list_sort for args list begin: %p cmp: %p\n"RST_COL, \
			begin_list, cmp);
	ft_list_sort(begin_list, cmp);
	printf("\tafter calling ft_list_sort\n");
	if (begin_list)
	{
		print_list(*begin_list);
		sort_ret = check_list_sort(*begin_list, cmp);
		printf("\tcheck sort result is: %d\n", sort_ret);
	}
	return (!sort_ret);
}

static int		test_list_sort_empty(void)
{
	t_list	*l = NULL;
	int		ret = 0;

	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	print_list(l);
	ret += test_list_sort(&l, strcmp);
	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	print_list(l);
	ret += test_list_sort(&l, ft_greater);
	printf(GRN_COL"\nClear the list with one node"RST_COL"\n");
	ft_list_remove_if(&l, NULL, ft_always_equal, NULL);	
	print_list(l);
	return (ret);
}

static t_list	*create_list_of_size(int number)
{
	char	buf[128];
	t_list	*l = NULL;
	int		i;
	char	*content;

	printf(GRN_COL"\nCreate a list with %d nodes"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %05d", off[i] * 10 + i);
		content = strdup(buf);
		ft_list_push_front(&l, content);
		printf(GRN_COL"\tpush node %p, data:\"%s\", next:%p"RST_COL"\n", l,\
				 (char*)l->data, l->next);
	}
	print_list(l);
	printf("\tcheck sort for greater result is: %d\n", \
			check_list_sort(l, ft_greater));
	printf("\tcheck sort for lesser result is: %d\n", \
			check_list_sort(l, ft_lesser));
	return (l);
}

static	void	clear_list(t_list **l, int number)
{
	printf(GRN_COL"\nClear the list with %d nodes"RST_COL"\n", number);
	ft_list_remove_if(l, NULL, ft_always_equal, free);
	if (l)
		print_list(*l);
}

int		test_list_sort_act(void)
{
	t_list	*l = NULL;
	int		number = 10;
	int		ret = 0;

	print_test_header("ft_list_sort");
	ret += test_list_sort_empty();
	l = create_list_of_size(number);
	printf("\tuse ft_greater to compare when sorting\n");

	ret += test_list_sort(&l, ft_greater);
	printf("\tstill use ft_greater\n");
	printf("\tsort, a list already sorted\n");

	ret += test_list_sort(&l, ft_greater);
	printf("\tuse ft_lesser to compare when sorting\n");
	ret += test_list_sort(&l, ft_lesser);

	clear_list(&l, number);
	return	(ret);
}
