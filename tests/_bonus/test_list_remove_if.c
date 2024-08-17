/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove_if.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:35:52 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 20:41:52 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

#ifndef test_size_rm_if
# define test_size_rm_if 10
#endif

static int		test_list_remove_if(t_list **begin_list, char *data_ref, \
			int (*cmp)(), void (*free_fct)(void *), int exp_decr)
{
	int		res = 0;
	int		prev_size = 0;
	int		after_size = 0;

	if (!begin_list)
		printf(GRN_COL"list passed is NULL"RST_COL"\n");
	else
	{
		prev_size = ft_list_size(*begin_list);
		if (prev_size == 0)	printf(GRN_COL"list passed is empty"RST_COL"\n");
		printf("Before call, the size of list is: %d\n", prev_size);
	}
	printf(GRN_COL"Using ft_list_remove_if"RST_COL"\n");
	printf(GRN_COL"\tTest to remove an element from a list when equals"\
				" data ref: \"%s\""RST_COL"\n", data_ref);
	ft_list_remove_if(begin_list, data_ref, cmp, free_fct);
	if (begin_list)
	{
		after_size = ft_list_size(*begin_list);
		printf("\tAfter call, the size of list is: %d\n", after_size);
		if (after_size != prev_size - exp_decr)
		{
			printf(RED_COL"\tDecreased size is NOT what's expected"RST_COL"\n");
			res++;
		}
	}
	else
		printf("\tAfter call, list is NULL\n");
	print_test_result(res);
	return	(res);
}

static t_list	*create_list_of_size(int number)
{
	t_list	*l;
	char	buf[128];
	char	*content;
	int		i;

	l = NULL;
	printf(GRN_COL"\nCreate a list with %d nodes"RST_COL"\n", number);
	for (i = 0; i < number; i++)
	{
		sprintf(buf, "content of node %d", i);
		content = strdup(buf);
		ft_list_push_front(&l, content);
	}
	return (l);
}

int		test_list_remove_if_act()
{
	t_list	*l;
	char	buf[128];
	int		i;
	int		res;

	l = NULL;
	res = 0;
	print_test_header("ft_list_remove_if");
	res += test_list_remove_if(NULL, "A", strcmp, NULL, 0);
	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	res += test_list_remove_if(&l, "A", strcmp, NULL, 0);
	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	res += test_list_remove_if(&l, "A", strcmp, NULL, 0);
	res += test_list_remove_if(&l, "static data", strcmp, NULL, 1);
	l = create_list_of_size(test_size_rm_if);
	for (i = 0; i < test_size_rm_if; i++)
	{
		sprintf(buf, "content of node %d", i);
		res += test_list_remove_if(&l, buf, strcmp, free, 1);
	}
	return	(res);
}
