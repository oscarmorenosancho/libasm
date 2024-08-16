#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

static int	test_strlen(const char *s)
{
	size_t	ret1;
	size_t	ret2;
	int	res;

	printf(GRN_COL"\nUsing ft_strlen\n"RST_COL);
	ret1 = ft_strlen(s);
	printf("counted chars in \"%s\": %zu\n", s, ret1);

	printf(BLU_COL"\nUsing strlen\n"RST_COL);
	ret2 = strlen(s);
	printf("counted chars in \"%s\": %zu\n", s, ret2);

	res = (ret1 != ret2);
	print_test_result(res);
	return (res);
}

int		test_strlen_act(void)
{
	int	ret;
	static const char *uc = CYN_COL"Some special characters 你好世界!\n"RST_COL;

	print_test_header("ft_strlen");
	ret = test_strlen(uc);
	ret += test_strlen("");
	return (ret);
}
