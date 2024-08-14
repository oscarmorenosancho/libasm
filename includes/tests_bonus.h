#ifndef _TESTS_BONUS_H
#define	_TESTS_BONUS_H

#include <sys/types.h>
#include <libasm_bonus.h>

int		test_isspace();
int		test_count_char(const char *ts);
int		test_get_index(const char *ts, const char *qs);
int		test_validate_base(const char *base);
int		test_trim_spaces(const char *str);
int		test_get_sign(char *str);
int		test_atoui_base(char *str, char *base);	
int		test_atoi_base(char *str, char *base);
int		test_create_elem(char *data);
int		test_list_push_front(t_list **begin_list, char *data);
int		test_list_push_node_front(t_list **begin_list, t_list *node);
int		test_list_size(t_list *begin_list);
int 	test_list_sort(t_list **begin_list, int (*cmp)());
int		test_destroy_elem(t_list *node, void (*free_fct)(void *));
int		test_list_pop_front(t_list **begin_list, int free_cont);
int		test_list_remove_front(t_list **begin_list, void (*free_fct)(void *));
int		test_list_search_pos(t_list **begin_list, char *data_ref, int (*cmp)());
int		test_list_remove_if(t_list **begin_list, char *data_ref, int (*cmp)(),\
							void (*free_fct)(void *));
int		test_list_sort(t_list **begin_list, int (*cmp)());

int		test_validate_base_examples();
int		test_trim_spaces_examples();
int		test_get_sign_examples();
int		test_atoui_base_examples();
int		test_atoi_base_examples();
int		test_list_push_node_front_examples();
int		test_list_size_examples();
int		test_destroy_elem_examples();
int		test_list_pop_examples();
int		test_list_remove_front_examples();
int		test_list_remove_if_examples();
int		test_list_search_pos_examples();
int		test_list_sort_examples();
void	print_list_node(t_list *node);
void	print_list(t_list *list);


#endif