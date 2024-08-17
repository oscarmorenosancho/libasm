#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>

static int		test_list_push_front(t_list **begin_list, char *data, int print_res)
{
	int		res;
	ssize_t	prev_len;

	prev_len = 0;
	res = 0;
	printf(GRN_COL"Using ft_list_push_front for args list begin: %p  data: \'%s\'\n"\
			RST_COL, begin_list, data);
	if (begin_list)	printf("\t list begin points at %p\n", *begin_list);
	else printf("\t no list provided\n");
	if (begin_list)
		prev_len = ft_list_size(*begin_list);
	ft_list_push_front(begin_list, data);
	printf("\tafter calling ft_list_push_front\n");
	if (begin_list)
	{
		t_list *n1 = *begin_list;
		if (n1)
		{
			printf("\tfirst node content data of list is: \"%s\"  next points to: %p\n", \
				(char*)n1->data, n1->next);
			res = (0!=strcmp((char*)n1->data, data));
		}
		else res++;
		if ((prev_len + 1) != ft_list_size(*begin_list)) res++;
		if (print_res) print_list(*begin_list);
	}
	print_test_result(res);
	return (res);
}

int		test_list_push_front_act(void)
{
	t_list *l = NULL;
	int		res;

	res = 0;
	print_test_header("ft_list_push_front");

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	res += test_list_push_front(&l, "static data", 0);

	printf(GRN_COL"\nPush another node to list"RST_COL"\n");
	res += test_list_push_front(&l, "static data 2", 1);

	ft_list_remove_if(&l, NULL, ft_always_equal, NULL);	
	printf(GRN_COL"Clear the list"RST_COL"\n");
	print_list(l);
	return (res);
}
