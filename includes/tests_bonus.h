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
int		test_create_elem(void *data);
int		test_list_push_front(t_list **begin_list, void *data);
int		test_list_size(t_list *begin_list);
int 	test_list_sort(t_list **begin_list, int (*cmp)());
int		test_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),\
							void (*free_fct)(void *));
int		test_validate_base_examples();
int		test_trim_spaces_examples();

#endif