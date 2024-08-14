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
	t_list	*n = NULL;

	printf(GRN_COL"Using ft_list_search_pos for args list begin: %p\n"RST_COL, begin_list);
	printf(GRN_COL"ref_data: \"%s\" (%p) cmp: %p\n"RST_COL, data_ref, data_ref, cmp);
	lr = ft_list_search_pos(begin_list, data_ref, cmp);
	if (lr) n = *lr;  
	printf("\tafter calling ft_list_search_pos, front list to insert: %p, node: %p\n", lr, n);
	if (n)
		printf("\tdata: \"%s\", next: %p\n", (char*)n->data, n->next);
	return (0);
}

int		test_list_search_pos_examples()
{
	t_list	*l = NULL;
	char	buf[128];
	char	*content;
	int		number = 10;
	int		i;

	print_test_header("ft_list_search_pos");

	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	test_list_search_pos(NULL, NULL, strcmp);

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	test_list_search_pos(&l, "", strcmp);
	test_list_search_pos(&l, "z", strcmp);

	printf(GRN_COL"\nClear the list with one node"RST_COL"\n");
	ft_list_remove_if(&l, "", ft_always_equal, NULL);	
	test_list_search_pos(&l, "", strcmp);

	printf(GRN_COL"\nCreate a list with %d nodes"RST_COL"\n", number);
	for (i = number - 1; i >= 0; i--)
	{
		sprintf(buf, "%05d", i);
		content = strdup(buf);
		ft_list_push_front(&l, content);
		printf(GRN_COL"\tpush node %p, data:\"%s\", next:%p"RST_COL"\n", l, (char*)l->data, l->next);
	}
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "%05d", i);
		test_list_search_pos(&l, buf, strcmp);
	}
	printf(GRN_COL"\nClear the list with %d nodes"RST_COL"\n", number);
	ft_list_remove_if(&l, NULL, ft_always_equal, free);	
	return	(0);

}
