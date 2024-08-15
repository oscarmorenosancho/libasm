#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>

int		check_list_sort(t_list *begin_list, int (*cmp)())
{
	int		is_sorted;
	t_list	*cur;
	char	*s1;
	char	*s2;

	is_sorted = 1;
	cur = begin_list;
	while(cur && cur->next && is_sorted)
	{
		s1 = cur->data;
		s2 = cur->next->data;
		is_sorted = (((*cmp)(s1, s2)) <= 0);
		cur = cur->next;
	}
	return (is_sorted);
}
