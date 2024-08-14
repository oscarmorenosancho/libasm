#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static int		always_equal(const char *s1, const char *s2)
{
	(void)s1;
	(void)s2;
	return (0);
}
int		test_list_push_front(t_list **begin_list, char *data)
{
	printf(GRN_COL"=======================\n"RST_COL);
	printf(GRN_COL"TEST ft_list_push_front\n"RST_COL);
	printf(GRN_COL"=======================\n\n"RST_COL);


	printf(GRN_COL"Using ft_list_push_front for args list begin: %p  \'%s\'\n"RST_COL, begin_list, data);
	if (begin_list)
	{
		printf("\t list begin points at %p\n", *begin_list);
	}
	else
	{
		printf("\t no list provided\n");
	}
	ft_list_push_front(begin_list, data);
	printf("\tafter calling ft_list_push_front\n");
	if (begin_list)
	{
		t_list *n1 = *begin_list;
		printf("\tfirst node content data of list is: \"%s\"  next points to: %p\n", (char*)n1->data, n1->next);
		free (n1);
	}
	return (0);
}

int		test_list_push_front_examples(void)
{
	t_list *l = NULL;

	printf(GRN_COL"\n============================\n"RST_COL);
	printf(GRN_COL"TEST ft_list_push_front\n"RST_COL);
	printf(GRN_COL"============================\n"RST_COL);

	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	print_list(l);

	printf(GRN_COL"\nPush another node to list"RST_COL"\n");
	ft_list_push_front(&l, "static data 2");
	print_list(l);

	ft_list_remove_if(&l, NULL, always_equal, NULL);	
	printf(GRN_COL"\nClear the list"RST_COL"\n");

	print_list(l);
	return (0);
}