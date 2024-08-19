/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:38:32 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/19 19:01:59 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

static const char	*hw = "Hello World!\n";
static const char	*hw2 = "Hello World! to stderr\n";
static const char	*tab = "\ttabulated\n";

static int	test_strcmp(const char *s1, const char *s2)
{
	int	ret1;
	int	ret2;
	int	res;

	printf(GRN_COL"\nUsing ft_strcmp\n"RST_COL);
	ret1 = ft_strcmp(s1, s2);
	printf("comparison between %s and %s: %d\n", s1, s2, ret1);
	printf(BLU_COL"\nUsing strcmp\n"RST_COL);
	ret2 = strcmp(s1, s2);
	printf("comparison between %s and %s: %d\n", s1, s2, ret2);
	res = (ret1 != ret2);
	print_test_result(res);
	return (res);
}

int	test_strcmp_act(void)
{
	int					ret;

	print_test_header("ft_strcmp");
	ret = test_strcmp("", "");	
	ret += test_strcmp("a", "a");	
	ret += test_strcmp("a", "b");	
	ret += test_strcmp("b", "a");	
	ret += test_strcmp("hw2", "hw");	
	ret += test_strcmp("hw*", "hw");	
	ret += test_strcmp("hw", "hw*");	
	ret += test_strcmp(tab, hw);	
	ret += test_strcmp(hw2, hw);
	ret += test_strcmp("\0", "\200");	
	ret += test_strcmp("\200", "\0");	
	return (ret);
}
