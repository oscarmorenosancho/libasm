/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:08:25 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/18 16:46:59 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

#ifndef test_list_size_sz
	#define test_list_size_sz 10
#endif

static int		test_list_size(t_list *begin_list, int exp_size)
{
	int	count;
	int	res;

	res = 0;
	printf(GRN_COL"Using ft_list_size for args list begin: %p\n"RST_COL, \
		begin_list);
	count = ft_list_size(begin_list);
	res = (count != exp_size);
	printf("\tafter calling ft_list_size, size is %d\n", count);
	print_test_result(res);
	return (res);
}
static t_list	*create_list_of_size(int number)
{
	char	buf[128];
	t_list	*l;
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


int		test_list_size_act()
{
	t_list	*l;
	int		res;

	res = 0;
	l = NULL;
	print_test_header("ft_list_size");
	res += test_list_size(NULL, 0);
	printf(GRN_COL"\nCreate an empty list"RST_COL"\n");
	res += test_list_size(NULL, 0);
	printf(GRN_COL"\nCreate a list with one node"RST_COL"\n");
	ft_list_push_front(&l, "static data");
	res += test_list_size(l, 1);
	clear_list(&l, NULL);
	res += test_list_size(l, 0);
	l = create_list_of_size(test_list_size_sz);
	res += test_list_size(l, test_list_size_sz);
	clear_list(&l, free);
	res += test_list_size(l, 0);
	return	(res);
}
