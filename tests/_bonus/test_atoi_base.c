#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_atoi_base(char *str, char *base)
{
	int	ret;

	printf(GRN_COL"\tUsing ft_atoi_base for arg \"%s\" and base \"%s\"\n"RST_COL, str, base);
	ret = ft_atoi_base(str, base);
	printf("\tvalue is: %d\n", ret);

	return (0);
}

int		test_atoi_base_examples()
{
	size_t		i;
	char		*strs[] = {"---15", "---FF", "---+8", "---F", "-", "--15x", "--FFx", "--8+", "--Fx", "--x", NULL};

	i = 0;
	while (strs[i])
	{
		test_atoi_base(strs[i], "01");
		test_atoi_base(strs[i], "0123456789");
		test_atoi_base(strs[i], "0123456789ABCDEF");
		i++;
	}
	return (0);
}
