/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_destroy_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:57:30 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 20:58:08 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static int		test_destroy_elem(t_list *node, void (*free_fct)(void *))
{
	int		res;

	res = 0;
	printf(GRN_COL"Using ft_destroy_elem for args node: %p free_fct: %p'\n"\
			RST_COL, node, free_fct);
	if (!node)
		printf(RED_COL"Using ft_destroy_elem needs a node to destroy'\n"RST_COL);
	ft_destroy_elem(node, free_fct);
	printf("After ft_destroy_elem'\n" );
	print_test_result(res);
	return	(res);
}

int		test_destroy_elem_act()
{
	t_list	*node;
	char	*content;
	int		res;

	res = 0;
	print_test_header("ft_destroy_elem");
	printf(GRN_COL"Test to destroy a NULL node"RST_COL);
	res += test_destroy_elem(NULL, NULL);
	printf(GRN_COL"Test to create a node with static " \
			"content and destroy it"RST_COL"\n");
	node = ft_create_elem("static content");
	res += test_destroy_elem(node, NULL);	
	printf(GRN_COL"Test to create a node with alloc'ed content" \
			" and destroy it"RST_COL"\n");
	content = strdup("alloc'ed content");
	node = ft_create_elem(content);
	res += test_destroy_elem(node, free);	
	return	(res);
}
