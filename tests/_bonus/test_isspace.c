#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>
#include <ctype.h>

static int	test_isspace(char c)
{
	int		res;
	int		ret1;
	int		ret2;

	printf(GRN_COL"Using ft_isspace for arg \'%c\'\n"RST_COL, c);
	ret2 = (isspace(c) != 0);
	ret1 = (ft_isspace(c) != 0);
	printf("for ft_isspace \'%c\': %s\n", c, ret1 ? "is space" : "is NOT space");
	printf("for    isspace \'%c\': %s\n", c, ret2 ? "is space" : "is NOT space");
	res = (ret1 != ret2);
	print_test_result(res);
	return (res);
}

int	test_isspace_act(void)
{
	int			is;
	int			ret;
	size_t		i;
	size_t		len;
	static char	ts[] = "s\b \t\n\v\f\r";

	ret = 0;
	print_test_header("ft_isspace");

	len = ft_strlen(ts);
	printf("\nTest all characters in \"%s\" with length %zu\n", ts, len);

	for (i = 0; i < len; i++)
	{
		is = test_isspace(ts[i]);
		ret = ret || is;
	}
	return (ret);
}
