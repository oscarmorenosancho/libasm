/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:37:05 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 19:37:08 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TESTS_BONUS_H
#define	_TESTS_BONUS_H

#include <sys/types.h>
#include <libasm_bonus.h>

int		ft_always_equal(const char *s1, const char *s2);
int		ft_greater(const char *s1, const char *s2);
int		ft_lesser(const char *s1, const char *s2);

int		check_list_sort(t_list *begin_list, int (*cmp)());
void 	clear_list(t_list **l, void (*free_fct)(void *));

int		test_isspace_act(void);
int		test_count_char_act(void);
int		test_get_index_act(void);
int		test_validate_base_act(void);
int		test_trim_spaces_act(void);
int		test_get_sign_act(void);
int		test_atoui_base_act(void);
int		test_atoi_base_act(void);
int		test_create_elem_act(void);
int		test_list_push_front_act(void);
int		test_list_push_node_front_act(void);
int		test_list_size_act(void);
int		test_destroy_elem_act(void);
int		test_list_pop_front_act(void);
int		test_list_remove_front_act(void);
int		test_list_remove_if_act(void);
int		test_list_search_pos_act(void);
int		test_list_sort_ins_act(void);
int		test_list_sort_act(void);

void	print_list_node(t_list *node);
void	print_list(t_list *list);
void	print_binary(long value);
void	print_binary_int(int value);

#endif