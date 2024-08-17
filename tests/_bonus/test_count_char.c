/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:56:49 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 20:56:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static const char base_str[] = "qwertyQWERTYr YY";
static const int exp_count[] = \
				{1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 3, 2, 1, 3, 3};

static int	test_count_1char(const char *ts, char c, int ec)
{
	int		res;
	int		ret;

	res = 0;
	printf(GRN_COL"\nUsing string \"%s\""RST_COL"\n", ts);
	printf(GRN_COL"\tUsing ft_count_char for arg \'%c\'\n"RST_COL, c);
	ret = ft_count_char(ts, c);
	if (ret != ec) res++;
	printf("\t\'%c\': is repeated %d times\n", c, ret );
	print_test_result(res);
	return (res);
}

static int	test_count_char(const char *ts, const int *ec)
{
	int		res;
	int		ret;
	size_t	len;
	size_t	i;

	res = 0;
	len = ft_strlen(ts);
	printf(GRN_COL"\nUsing string \"%s\""RST_COL"\n", ts);
	for (i = 0; i < len; i++)
	{
		printf(GRN_COL"\tUsing ft_count_char for arg \'%c\'\n"RST_COL, ts[i]);
		ret = ft_count_char(ts, ts[i]);
		if (ret != ec[i]) res++;
		printf("\t\'%c\': is repeated %d times\n", ts[i], ret );
	}
	print_test_result(res);
	return (res);
}

int	test_count_char_act(void)
{
	int	ret;

	ret = 0;
	print_test_header("ft_count_char");
	ret += test_count_char(base_str, exp_count);
	ret += test_count_1char(base_str, 'Z', 0);
	return (ret);
}