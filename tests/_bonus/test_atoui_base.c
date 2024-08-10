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
	char		*strs[] = {"", "8", "F", "15", "FF", NULL};

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
