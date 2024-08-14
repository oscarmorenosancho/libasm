#include <stdio.h>
#include <libasm.h>
#include <tests.h>

int main(int argc, char **argv)
{
	int		failed_tests;
	char	buf[128];
	static char	err_msg[] = RED_COL"Error only one argument or none can be used"RST_COL"\n";

	failed_tests = 0;

	if (argc > 2)
	{
		ft_write(2, err_msg, ft_strlen(err_msg));
		return(1);
	}
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
	if (failed_tests > 0)
	{
		sprintf(buf, RED_COL"FAILED TESTS: %d"RST_COL"\n", failed_tests);
		ft_write(2, buf, ft_strlen(buf));
		return (failed_tests);
	}
	return (0);
}

