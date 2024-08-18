/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_search_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:08:35 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/18 16:24:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

#ifndef test_serch_sz
# define test_serch_sz 10
#endif

static int test_list_search_pos(t_list **begin_list, char *data_ref, \
								int (*cmp)(), t_list **exp_find)
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
		" expected find: %p\n", lr, exp_find);
	printf("\tafter calling ft_list_search_pos node at front: %p\n", n);
	if (n)
		printf("\tdata: \"%s\", next: %p\n", (char*)n->data, n->next);
	res = (lr != exp_find);
	print_test_result(res);
	return (res);
}

static	void	create_list_of_size(t_list	**l, int number)
{
	char	buf[128];
	char	*content;
	int		i;

	printf(GRN_COL"\nCreate a list with %d nodes"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "%05d", i);
		content = strdup(buf);
		ft_list_push_front(l, content);
		printf(GRN_COL"\tpush node %p, data:\"%s\", next:%p"RST_COL"\n", \
			*l, (char*)(*l)->data, (*l)->next);
	}
	printf("\n");
}

static int	test_locate_at_head(int number)
{
	char	buf[128];
	t_list	*l;
	int		res;
	int		i;

	res = 0;
	l = NULL;
	create_list_of_size(&l, number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "%05d", i);
		res += test_list_search_pos(&l, buf, strcmp, &l);
	}
	print_list(l);
	clear_list(&l, free);
	return (res);
}

static int	test_locate_at_tail(int number)
{
	t_list	*l;
	t_list	*n;
	int		res;

	l = NULL;
	res = 0;
	n = ft_create_elem(strdup("**"));
	ft_list_push_node_front(&l, n);
	create_list_of_size(&l, number);
	print_list(l);
	printf("Searching for lesser then \"*\"\n");
	res += test_list_search_pos(&l, "*", ft_lesser, &(n->next));
	clear_list(&l, free);
	return (res);
}

int		test_list_search_pos_act()
{
	t_list	*l;
	int		res;

	(void)test_locate_at_head;
	(void)test_locate_at_tail;
	l = NULL;
	res = 0;
	print_test_header("ft_list_search_pos");
	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	res += test_list_search_pos(NULL, NULL, strcmp, NULL);
	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	res += test_list_search_pos(&l, "", strcmp, &l);
	res += test_list_search_pos(&l, "z", strcmp, &(l->next));
	clear_list(&l, NULL);
	res += test_list_search_pos(&l, "", strcmp, &l);
	res += test_locate_at_head(test_serch_sz);
	res += test_locate_at_tail(test_serch_sz);
	return	(res);
}
