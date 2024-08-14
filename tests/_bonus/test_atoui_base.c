#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_atoui_base(char *str, char *base)
{
	size_t	ret;

	printf(GRN_COL"\tUsing ft_atoui_base for arg \"%s\" and base \"%s\"\n"RST_COL, str, base);
	ret = ft_atoui_base(str, base);
	printf("\tvalue is: %zu\n", ret);

	return (0);
}

int		test_atoui_base_examples()
{
	size_t		i;
	char		*strs[] = { "10000000000000000000000000000000", "-10000000000000000000000000000000",
							"1000000000000000", "-1000000000000000",
							"FFFFFFFFFFFFFFFF", "-FFFFFFFFFFFFFFFF",
							"15", "FF", "8", "F", "",
							"15x", "FFx", "8x",
							"Fx", "x", NULL };

	printf(GRN_COL"\n============================\n"RST_COL);
	printf(GRN_COL"TEST ft_atoui_base\n"RST_COL);
	printf(GRN_COL"============================\n"RST_COL);

	i = 0;
	while (strs[i])
	{
		test_atoui_base(strs[i], "01");
		test_atoui_base(strs[i], "0123456789");
		test_atoui_base(strs[i], "0123456789ABCDEF");
		i++;
	}
	return (0);
}
