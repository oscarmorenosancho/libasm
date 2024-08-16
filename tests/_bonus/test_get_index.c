#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static int	test_get_index(const char *ts, const char *qs)
{
	ssize_t	ret;
	size_t	len;
	size_t	i;

	print_test_header("ft_get_index");

	len = ft_strlen(qs);

	printf(GRN_COL"\nUsing string \"%s\""RST_COL"\n", ts);
	for (i = 0; i < len; i++)
	{
		printf(GRN_COL"\tUsing ft_get_index for arg \'%c\'\n"RST_COL, qs[i]);
		ret = ft_get_index(ts, qs[i]);
		printf("\t\'%c\': is located at position %zd\n", qs[i], ret );
	}
	return (0);
}

int	test_get_index_act(void)
{
	int	ret;
	static const char	*plain = \
		"Plain text and some special characters 你好世界! to copy";

	ret = test_get_index(plain, "qwertyQWERTYP你");
	return (ret);
}