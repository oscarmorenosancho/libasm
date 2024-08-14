#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int	test_get_sign(char *str)
{
	int		sign;
	char	*remain;

	remain = str;

	printf(GRN_COL"\tUsing ft_get_sign for arg \"%s\"\n"RST_COL, str);
	sign = ft_get_sign(&remain);
	printf("\tsign is: %d, remaining string is \"%s\"\n", sign, remain);
	return (0);
}

int	test_get_sign_examples()
{
	size_t		i;
	char		*strs[] = {"++", "--", "---", "---- +", "", " ", "++8BF", "--8+", "-----U", "8", NULL};

	printf(GRN_COL"\n============================\n"RST_COL);
	printf(GRN_COL"TEST ft_get_sign\n"RST_COL);
	printf(GRN_COL"============================\n"RST_COL);

	i = 0;
	while (strs[i])
	{
		test_get_sign(strs[i]);
		i++;
	}
	test_get_sign(strs[i]);
	return (0);
}