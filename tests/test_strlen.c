#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

int	test_strlen(const char *s)
{
	size_t	ret;

	print_test_header("ft_strlen");

	printf(GRN_COL"\nUsing ft_strlen\n"RST_COL);
	ret = ft_strlen(s);
	printf("counted chars in %s: %zu\n", s, ret);

	printf(BLU_COL"\nUsing strlen\n"RST_COL);
	ret = strlen(s);
	printf("counted chars in %s: %zu\n", s, ret);
	return (0);
}

int		test_strlen_examples(void)
{
	static const char *uc = CYN_COL"Some special characters 你好世界!\n"RST_COL;
	test_strlen(uc);

	return (0);
}
