/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:57:22 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 20:57:23 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static const char	content[] = "node content";

static int		test_create_elem(char *data, void (*free_fct)(void *))
{
	t_list	*n1;
	int		res;

	res = 0;
	printf(GRN_COL"\tUsing ft_create_elem for arg \'%s\'\n"RST_COL, data);
	n1 = ft_create_elem(data);
	if (n1)
	{
		printf("\tnode content data is: \"%s\"  next points to: %p\n", \
			(char*)n1->data, n1->next);
		if (free_fct)	free_fct (n1);
	}
	else
	{
		printf("\tfail to create element");
		perror(RED_COL"Error"RST_COL);
	}
	print_test_result(res);
	return (res);
}

int	test_create_elem_act(void)
{
	int		ret;
	char 	*dup;

	ret = 0;
	print_test_header("ft_create_elem");
	dup = strdup("dynamic content");
	ret += test_create_elem((char*)content, NULL);
	ret += test_create_elem(dup, free);
	return (ret);
}
