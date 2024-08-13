#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int test_list_search_pos(t_list **begin_list, char *data_ref, int (*cmp)())
{
	t_list	**lr;
	printf(GRN_COL"Using ft_list_search_pos for args list begin: %p\n"RST_COL, begin_list);
	printf(GRN_COL"ref_data: \"%s\" cmp: %p\n"RST_COL, data_ref, cmp);
	lr = ft_list_search_pos(begin_list, data_ref, cmp);
	printf("\tafter calling ft_list_search_pos, front list to insert %p\n", lr);
	return (0);
}

static int		always_equal(const char *s1, const char *s2)
{
	(void)s1;
	(void)s2;
	return (0);
}

int		test_list_search_pos_examples()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;

	// printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	// test_list_search_pos(NULL, NULL, strcmp);

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	test_list_search_pos(&l, "", strcmp);

	printf(GRN_COL"\nClear the list with one node"RST_COL"\n");
	// ft_list_remove_front(&l, NULL);
	ft_list_remove_if(&l, "", always_equal, NULL);	
	test_list_search_pos(&l, "", strcmp);

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
		test_list_search_pos(&l, buf, strcmp);
	}
	printf(GRN_COL"\nClear the list with %d nodes"RST_COL"\n", number);
	ft_list_remove_if(&l, NULL, always_equal, free);	
	return	(0);

}
