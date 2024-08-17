#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

#ifndef test_list_size
	#define	test_list_size 10
#endif

static const int	off[] = {5, 7, 1, 4, 6, 3, 0, 9, 8, 2};

static int		test_list_sort_ins(t_list **begin_list, \
					char *content, int (*cmp)())
{
	t_list *node;
	int		res;
	int		prev_size;
	int		after_size;

	res = 0;
	if (begin_list)
	{
		prev_size = ft_list_size(*begin_list);
		node = ft_create_elem(content);
		printf("\tNode created is %p content is: \"%s\"\n",\
				 node, (char*)node->data);
		printf("\tsize before insert %d\n", prev_size);
		printf(GRN_COL"\tTest to ins an element sorted on list by "\
				"ft_list_sort_ins"RST_COL"\n");
		ft_list_sort_ins(begin_list, node, cmp);
		after_size = ft_list_size(*begin_list);
		res = (prev_size + 1 != after_size);
		if (!check_list_sort(*begin_list, cmp)) res++;
		printf("\tsize after insert %d\n", after_size);
	}
	else
		printf(ORG_COL"\tNo list provided"RED_COL"\n");
	print_test_result(res);
	return	(res);
}

static	int		test_create_sorted_of_size(t_list **l, int number)
{
	char	buf[128];
	int 	res;
	int		i;
	char	*content;

	res = 0;
	*l = NULL;
	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	print_list(*l);
	printf(GRN_COL"\nCreate a list with %d node"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %05d", off[i] * 10 + i);
		content = strdup(buf);
		res = test_list_sort_ins(l, content, ft_greater);
	}
	print_list(*l);
	return (res);
}

static void clear_list(t_list **l, void (*free_fct)(void *))
{
	printf(GRN_COL"\nClear list"RST_COL"\n");
	ft_list_remove_if(l, NULL, ft_always_equal, free_fct);
	print_list(*l);
}	

int		test_list_sort_ins_act()
{
	t_list	*l;
	int		res;

	l = NULL;
	res = 0;
	print_test_header("ft_list_sort_ins");
	printf(GRN_COL"Test to insert an element to NULL list"RST_COL"\n");
	res += test_list_sort_ins(NULL, "inserted", ft_greater);
	clear_list(&l, NULL);
	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	print_list(l);
	res += test_list_sort_ins(&l, "inserted", ft_greater);
	print_list(l);
	clear_list(&l, NULL);
	res = test_create_sorted_of_size(&l, test_list_size);
	clear_list(&l, free);
	return	(res);
}
