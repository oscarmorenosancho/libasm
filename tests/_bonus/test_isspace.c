#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int	test_isspace(char c)
{
	int		ret;

	printf(GRN_COL"\nUsing ft_isspace for arg \'%c\'\n"RST_COL, c);
	ret = ft_isspace(c);
	printf("\'%c\': %s\n", c, ret ? "is space" : "is NOT space");
	return (0);
}

int	test_isspace_examples(void)
{
	int	ret;
	size_t	i;
	size_t	len;
	char	ts[] = "\rs \t\n";

	print_test_header("ft_isspace");

	len = ft_strlen(ts);

	for (i = 0; i < len; i++)
	{
		ret = test_isspace(ts[i]);
	}
	return (0);
}