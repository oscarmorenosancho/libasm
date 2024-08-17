/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:38:07 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 19:38:09 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libasm.h>
#include <tests.h>

typedef struct s_lookup
{
	char	*key;
	int		(*action)();
}	t_lookup;

static const char	err_msg[] = \
		RED_COL"Error only one argument or none can be used"RST_COL"\n";

static t_lookup lu_table[] = { \
	{"strlen", test_strlen_act }, \
	{"strcpy", test_strcpy_act }, \
	{"strdup", test_strdup_act }, \
	{"strcmp", test_strcmp_act }, \
	{"write", test_write_act }, \
	{"read", test_read_act }, \
	{NULL, NULL}
	};

static int	print_fails(int failed_tests)
{
	char		buf[128];

	if (failed_tests > 0)
	{
		sprintf(buf, RED_COL"FAILED TESTS: %d"RST_COL"\n", failed_tests);
		ft_write(2, buf, ft_strlen(buf));
		return (failed_tests);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int			failed_tests;
	int			arg_is_bonus;
	int			it;

	failed_tests = 0;
	if (argc > 2)
	{
		ft_write(2, err_msg, ft_strlen(err_msg));
		return(1);
	}
	arg_is_bonus = (argc == 2 && !ft_strcmp(argv[1], "bonus"));
	it = 0;
	while (lu_table[it].key)
	{
		if ((argc == 1 || (argc == 2 && !ft_strcmp(argv[1], lu_table[it].key))))
			failed_tests += lu_table[it].action();
		it++;
	}
	return (print_fails(failed_tests));
}
