#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static const char	err_msg[] = RED_COL"Error only one argument or none can be used"RST_COL"\n";
static const char	*plain = "Plain text and some special characters 你好世界! to copy";

int main(int argc, char **argv)
{
	int		failed_tests;
	int		arg_is_bonus;
	char	buf[128];
	char	*content;
	
	content = "content";
	failed_tests = 0;

	if (argc > 2)
	{
		ft_write(2, err_msg, ft_strlen(err_msg));
		return(1);
	}

	arg_is_bonus = (argc == 1 || !ft_strcmp(argv[1], "bonus"));

	if (argc == 1 || !ft_strcmp(argv[1], "strlen"))
		failed_tests += test_strlen_examples();
	if (argc == 1 || !ft_strcmp(argv[1], "strcpy"))
		failed_tests += test_strcpy_examples();
	if (argc == 1 || !ft_strcmp(argv[1], "strdup"))
		failed_tests += test_strdup_examples();
	if (argc == 1 || !ft_strcmp(argv[1], "strcmp"))
		failed_tests += test_strcmp_examples();
	if (argc == 1 || !ft_strcmp(argv[1], "write"))
		failed_tests += test_write_examples();
	if (argc == 1 || !ft_strcmp(argv[1], "read"))
		failed_tests += test_read_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "isspace"))
		failed_tests += test_isspace();
	if (arg_is_bonus || !ft_strcmp(argv[1], "count_char"))
		failed_tests += test_count_char("qwertyQWERTYr YY");
	if (arg_is_bonus || !ft_strcmp(argv[1], "get_index"))
		failed_tests += test_get_index(plain, "qwertyQWERTYP你");
	if (arg_is_bonus || !ft_strcmp(argv[1], "validate_base"))
		failed_tests += test_validate_base_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "trim_spaces"))
		failed_tests += test_trim_spaces_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "get_sign"))
		failed_tests += test_get_sign_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "atoui_base"))
		failed_tests += test_atoui_base_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "atoi_base"))
		failed_tests += test_atoi_base_examples();

	if (arg_is_bonus || !ft_strcmp(argv[1], "create_elem"))
		failed_tests += test_create_elem(content);
	if (arg_is_bonus || !ft_strcmp(argv[1], "push_front"))
		failed_tests += test_list_push_front_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "push_node_front"))
		failed_tests += test_list_push_node_front_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "list_size"))
		failed_tests += test_list_size_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "destroy_elem"))
		test_destroy_elem_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "list_pop_front"))
		failed_tests += test_list_pop_front_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "list_remove_front"))
		failed_tests += test_list_remove_front_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "list_remove_if"))
		failed_tests += test_list_remove_if_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "list_search_pos"))
		failed_tests += test_list_search_pos_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "list_sort_ins"))
		failed_tests += test_list_sort_ins_examples();
	if (arg_is_bonus || !ft_strcmp(argv[1], "list_sort"))
		failed_tests += test_list_sort_examples();

	if (failed_tests > 0)
	{
		sprintf(buf, RED_COL"FAILED TESTS: %d"RST_COL"\n", failed_tests);
		ft_write(2, buf, ft_strlen(buf));
		return (failed_tests);
	}
	return (0);
}
