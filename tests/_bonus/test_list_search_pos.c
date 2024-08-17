/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_search_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:08:35 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 20:43:00 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static int test_list_search_pos(t_list **begin_list, char *data_ref\
								, int (*cmp)(), t_list **exp_find)
{
	t_list	**lr;
	t_list	*n;
	int		res;

	res = 0;
	n = NULL;
	printf(GRN_COL"Using ft_list_search_pos for args list begin: %p\n" \
		RST_COL, begin_list);
	printf(GRN_COL"ref_data: \"%s\" (%p) cmp: %p\n"RST_COL, \
		data_ref, data_ref, cmp);
	lr = ft_list_search_pos(begin_list, data_ref, cmp);
	if (lr) n = *lr;
	printf("\tafter calling ft_list_search_pos, front list to insert: %p," \
		" node: %p\n", lr, n);
	if (n)
		printf("\tdata: \"%s\", next: %p\n", (char*)n->data, n->next);
	res = (lr == exp_find);
	print_test_result(res);
	return (res);
}

static	t_list	*create_list_of_size(int number)
{
	t_list	*l;
	char	buf[128];
	char	*content;
	int		i;

	l = NULL;
	printf(GRN_COL"\nCreate a list with %d nodes"RST_COL"\n", number);
	for (i = number - 1; i >= 0; i--)
	{
		sprintf(buf, "%05d", i);
		content = strdup(buf);
		ft_list_push_front(&l, content);
		printf(GRN_COL"\tpush node %p, data:\"%s\", next:%p"RST_COL"\n", \
			l, (char*)l->data, l->next);
	}
	return (l);
}

int		test_list_search_pos_act()
{
	char	buf[128];
	t_list	*l;
	int		number = 10;
	int		res;
	int		i;

	l = NULL;
	res = 0;
	print_test_header("ft_list_search_pos");
	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	res += test_list_search_pos(NULL, NULL, strcmp, NULL);
	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	res += test_list_search_pos(&l, "", strcmp, &l);
	res += test_list_search_pos(&l, "z", strcmp, &l);
	clear_list(&l, NULL);
	res += test_list_search_pos(&l, "", strcmp, &l);
	l = create_list_of_size(number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "%05d", i);
		res += test_list_search_pos(&l, buf, strcmp, &l);
	}
	clear_list(&l, free);
	return	(res);
}
