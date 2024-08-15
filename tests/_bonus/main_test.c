/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:21:36 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/15 18:37:33 by omoreno-         ###   ########.fr       */
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
}	t_lookup;

static const char	err_msg[] = \
		RED_COL"Error only one argument or none can be used"RST_COL"\n";

static t_lookup lu_table[] = { \
	{"strlen", test_strlen_examples }, \
	{"strcpy", test_strcpy_examples }, \
	{"strdup", test_strdup_examples }, \
	{"strcmp", test_strcmp_examples }, \
	{"write", test_write_examples }, \
	{"read", test_read_examples }, \

	{"isspace", test_isspace_examples}, \
	{"count_char", test_count_char_examples}, \
	{"get_index", test_get_index_examples}, \
	{"validate_base", test_validate_base_examples}, \
	{"trim_spaces", test_trim_spaces_examples}, \
	{"get_sign", test_get_sign_examples}, \
	{"atoui_base", test_atoui_base_examples}, \
	{"atoi_base", test_atoi_base_examples}, \
	{"create_elem", test_create_elem}, \
	{"list_push_front", test_list_push_front_examples}, \
	{"list_push_node_front", test_list_push_node_front_examples}, \
	{"list_size", test_list_size_examples}, \
	{"destroy_elem", test_destroy_elem_examples}, \
	{"list_pop_front", test_list_pop_front_examples}, \
	{"list_remove_front", test_list_remove_front_examples}, \
	{"list_remove_if", test_list_remove_if_examples}, \
	{"list_search_pos", test_list_search_pos_examples}, \
	{"list_sort_ins", test_list_sort_ins_examples}, \
	{"list_sort", test_list_sort_examples}, \
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
		int arg_t = (it > 5) ? (arg_is_bonus) : argc == 1 ;
		if ((arg_t || (argc == 2 && !ft_strcmp(argv[1], lu_table[it].key))))
			failed_tests += lu_table[it].action();
		it++;
	}
	return (print_fails(failed_tests));
}
