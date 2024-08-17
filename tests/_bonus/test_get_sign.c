#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static char	*strs[] = {"++", "--", "---", "---- +", "", \
							" ", "++8BF", "--8+", "-----U", "8", NULL};
static int  expect[] = { 1,     1,      -1,     1,       1, \
							  1,	  1,      1,      -1,      1, 1 };

static int	test_get_sign(char *str, int exp)
{
	int		sign;
	char	*remain;
	int		res;

	remain = str;
	printf(GRN_COL"\tUsing ft_get_sign for arg \"%s\"\n"RST_COL, str);
	sign = ft_get_sign(&remain);
	res = (sign != exp);
	printf("\tsign is: %d, remaining string is \"%s\"\n", sign, remain);
	print_test_result (res);
	return (res);
}

int	test_get_sign_act()
{
	size_t		i;
	int		res;

	i = 0;
	res = 0;
	print_test_header("ft_get_sign");
	while (strs[i])
	{
		res += test_get_sign(strs[i], expect[i]);
		i++;
	}
	res += test_get_sign(strs[i], expect[i]);
	return (res);
}
