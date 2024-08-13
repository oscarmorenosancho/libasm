#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_list_remove_if(t_list **begin_list, char *data_ref, int (*cmp)(),\
							void (*free_fct)(void *))
{
	// t_list *node;
	if (!begin_list)
		printf(GRN_COL"list passed is NULL"RST_COL"\n");
	else
	{
		if (!(*begin_list))
			printf(GRN_COL"list passed is empty"RST_COL"\n");
		printf("Before call, the size of list is: %d\n", ft_list_size(*begin_list));
	}
	printf(GRN_COL"Using ft_list_remove_if"RST_COL"\n");
	printf(GRN_COL"\tTest to remove an element from a list when equals data ref: \"%s\""RST_COL"\n", data_ref);
	ft_list_remove_if(begin_list, data_ref, cmp, free_fct);
	if (begin_list)
		printf("\tAfter call, the size of list is: %d\n", ft_list_size(*begin_list));
	else
		printf("\tAfter call, list is NULL\n");
	// printf(GRN_COL"node content content is: \"%s\""RST_COL"\n", (char *)node->data);
	return	(0);
}

int		test_list_remove_if_examples()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;


	test_list_remove_if(NULL, "A", strcmp, NULL);

	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	test_list_remove_if(&l, "A", strcmp, NULL);

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	test_list_remove_if(&l, "A", strcmp, NULL);
	test_list_remove_if(&l, "static data", strcmp, NULL);

	printf(GRN_COL"\nCreate a list with %d nodes"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %d", i);
		content = strdup(buf);
		ft_list_push_front(&l, content);
	}
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %d", i);
		test_list_remove_if(&l, buf, strcmp, free);
	}
	return	(0);
}
