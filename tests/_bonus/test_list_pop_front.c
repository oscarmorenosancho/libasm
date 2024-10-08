/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_pop_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:50:42 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 20:55:09 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

#ifndef test_pop_sz
# define test_pop_sz 10
#endif

static int		test_list_pop_front(t_list **begin_list, \
												void (*free_fct)(void *))
{
	t_list *node;
	int		res;
	int		prev_len;
	void	*prev_data;

	res = 0;
	node = NULL;
	prev_len = 0;
	prev_data = NULL;
	if (begin_list)
	{
		prev_len = ft_list_size(*begin_list);
		if (prev_len > 0)
			prev_data = (*begin_list)->data;
	}
	printf(GRN_COL"Test to pop an element from a list by ft_list_pop_front"\
			RST_COL"\n");
	node = ft_list_pop_front(begin_list);
	if (prev_len == 0 && !node)
	{
		printf(GRN_COL"From empty list ft_list_pop_front don't get a node\n"\
			RST_COL"\n");
		if (begin_list)
			res =  (ft_list_size(*begin_list) != prev_len);
	}
	else if (prev_len == 0 && node)
	{
		res++;
		printf(RED_COL"Can't get a node by ft_list_pop_front from empty list"\
				RST_COL"\n");
	}
	else if (prev_len > 0 && !node)
	{
		res++;
		printf(RED_COL "Can't get a node by ft_list_pop_front " \
			"from a non empty list"RST_COL"\n");
	}
	else
	{
		printf("\tNode popped by ft_list_pop_front content is: %p\n", node);
		res = (node->data != prev_data);
		if (*begin_list && (*begin_list)->data == node->data) res++;
		printf("\tPopped node content is: \"%s\"\n", (char *)node->data);
		if ((prev_len - ft_list_size(*begin_list)) != 1) res++;
		ft_destroy_elem(node, free_fct);
	}
	print_test_result(res);
	return (res);
}
static t_list	*create_list_of_size(int number)
{
	t_list	*l;
	char	buf[128];
	int		i;

	l = NULL;
	printf(GRN_COL"\nCreate a list with %d node"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %d", i);
		ft_list_push_front(&l, strdup(buf));
	}
	print_list(l);
	return(l);
}

int		test_list_pop_front_act()
{
	t_list	*l;
	int		i;
	int		res;

	res = 0;
	l = NULL;
	print_test_header("ft_list_pop_front");
	printf(GRN_COL"Test to pop an element from NULL"RST_COL"\n");
	res += test_list_pop_front(NULL, 0);
	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	print_list(l);
	res += test_list_pop_front(&l, free);
	print_list(l);
	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, strdup("dynamic data"));
	print_list(l);
	res += test_list_pop_front(&l, free);
	print_list(l);
	l = create_list_of_size(test_pop_sz);
	for (i = 0; i < test_pop_sz; i++)
		res += test_list_pop_front(&l, free);
	print_list(l);
	return	(res);
}
