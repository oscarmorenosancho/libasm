#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static int		test_list_remove_front(t_list **begin_list, void (*free_fct)(void *))
{
	int		res = 0;
	int		prev_len = 0;
	void	*prev_data = NULL;

	if (!begin_list)
		printf(GRN_COL"list passed is NULL"RST_COL"\n");
	else
	{
		prev_len = ft_list_size(*begin_list);
		if (prev_len > 0)
			prev_data = (*begin_list)->data;
		else	printf(GRN_COL"list passed is empty"RST_COL"\n");
	}
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
		if (prev_len == 0)
		{
			printf(GRN_COL"From empty list ft_list_pop_front don't get a node\n"RST_COL"\n");
			res =  (ft_list_size(*begin_list) != prev_len);
			if (res)
				printf(RED_COL"Size can NOT change if list was empty"RST_COL"\n");
		}
		else
		{
			t_list	*node = *begin_list;
			printf(GRN_COL"front node in list is %p"RST_COL"\n", node);
			if (node)
			{
				printf(GRN_COL"front node content is %s, next is %p"RST_COL"\n", (char*)node->data, node->next);
				res = (node->data == prev_data);
			}
			int cur_len = ft_list_size(*begin_list);
			if ((prev_len - cur_len) != 1)
			{
				printf(RED_COL"Current size: %d vs previous size %d"RST_COL"\n", prev_len, cur_len);
				printf(RED_COL"Size has NOT decreased 1"RST_COL"\n");
				res++;
			}
		}		
	}
	print_test_result(res);
	return	(res);
}

int		test_list_remove_front_act()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;
	int		res = 0;

	print_test_header("ft_list_remove_front");

	res += test_list_remove_front(NULL, NULL);

	printf(GRN_COL"Create an empty list"RST_COL"\n");
	res += test_list_remove_front(&l, NULL);

	printf(GRN_COL"Create a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	res += test_list_remove_front(&l, NULL);

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
		res += test_list_remove_front(&l, free);
	}
	return	(res);
}
