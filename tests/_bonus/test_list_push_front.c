#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_list_push_front(t_list **begin_list, char *data)
{
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

