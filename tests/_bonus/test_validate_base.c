/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:23:06 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/18 13:48:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

typedef struct s_val_base_tests
{
	char	*base;
	int		expect;
}	t_val_base_tests;

static const t_val_base_tests base_tests[] = {
	{"01", 1},
	{"0123456789", 1},
	{"0123456789abcdef", 1},
	{"!@#$^&*()[]{}%=\\/~|.,?", 1},
	{"QWERTY", 1},
	{"ABCXYZ", 1},
	{"qwertyQWERTY", 1},
	{"abcxyzABCXYZ", 1},
	{"01234567895", 0},
	{"0123456789+", 0},
	{"0123456789-", 0},
	{"0123456789 ", 0},
	{"0123456789\t", 0},
	{"0123456789\n", 0},
	{"", 0},
	{"0", 0},
	{NULL, 0},
};

static int	test_validate_base(const t_val_base_tests *test)
{
	int	ret;
	int	res;

	printf(GRN_COL"\tUsing ft_validate_base for arg \"%s\"\n"RST_COL, test->base);
	ret = ft_validate_base(test->base);
	printf("\tbase \"%s\": %s\n", test->base, ret ? "is valid" : "is NOT valid");
	res = (ret != test->expect);
	print_test_result(res);
	return (res);
}

int	test_validate_base_act()
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	print_test_header("ft_validate_base");
	while (base_tests[i].base)
	{
		res += test_validate_base(base_tests + i);
		i++;
	}
	res += test_validate_base(base_tests + i);
	return (res);
}
