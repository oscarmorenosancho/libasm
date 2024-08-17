/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:21:36 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 18:07:09 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

typedef struct s_lookup
{
	char	*key;
	int		(*action)();
	int		core;
}	t_lookup;

static const char	err_msg[] = \
		RED_COL"Error only one argument or none can be used"RST_COL"\n";

static t_lookup lu_table[] = { \
	{"strlen", test_strlen_act, 1 }, \
	{"strcpy", test_strcpy_act, 1 }, \
	{"strdup", test_strdup_act, 1 }, \
	{"strcmp", test_strcmp_act, 1 }, \
	{"write", test_write_act, 1 }, \
	{"read", test_read_act, 1 }, \

	{"isspace", test_isspace_act, 0}, \
	{"count_char", test_count_char_act, 0}, \
	{"get_index", test_get_index_act, 0}, \
	{"validate_base", test_validate_base_act, 0}, \
	{"trim_spaces", test_trim_spaces_act, 0}, \
	{"get_sign", test_get_sign_act, 0}, \
	{"atoui_base", test_atoui_base_act, 0}, \
	{"atoi_base", test_atoi_base_act, 1}, \
	{"create_elem", test_create_elem_act, 0}, \
	{"list_push_front", test_list_push_front_act, 1}, \
	{"list_push_node_front", test_list_push_node_front_act, 0}, \
	{"list_size", test_list_size_act, 1}, \
	{"destroy_elem", test_destroy_elem_act, 0}, \
	{"list_pop_front", test_list_pop_front_act, 0}, \
	{"list_remove_front", test_list_remove_front_act, 0}, \
	{"list_remove_if", test_list_remove_if_act, 1}, \
	{"list_search_pos", test_list_search_pos_act, 0}, \
	{"list_sort_ins", test_list_sort_ins_act, 0}, \
	{"list_sort", test_list_sort_act, 1}, \
	{NULL, NULL, 0}
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
	int			arg_is_bonus_plus;
	int			arg_is_bonus;
	int			it;

	failed_tests = 0;
	if (argc > 2)
	{
		ft_write(2, err_msg, ft_strlen(err_msg));
		return(1);
	}
	arg_is_bonus_plus = (argc == 2 && !ft_strcmp(argv[1], "bonusp"));
	arg_is_bonus = (argc == 2 && !ft_strcmp(argv[1], "bonus"));
	it = 0;
	while (lu_table[it].key)
	{
		int arg_b = (arg_is_bonus && lu_table[it].core) || arg_is_bonus_plus;
		int arg_t = (it > 5) ? arg_b : argc == 1 ;
		if ((arg_t || (argc == 2 && !ft_strcmp(argv[1], lu_table[it].key))))
			failed_tests += lu_table[it].action();
		it++;
	}
	return (print_fails(failed_tests));
}
