#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int	test_isspace()
{
	int		ret;
	size_t	len;
	size_t	i;
	char	ts[] = "\rs \t\n";

	len = ft_strlen(ts);

	for (i = 0; i < len; i++)
	{
		printf(GRN_COL"\nUsing ft_isspace for arg \'%c\'\n"RST_COL, ts[i]);
		ret = ft_isspace(ts[i]);
		printf("\'%c\': %s\n", ts[i], ret ? "is space" : "is NOT space");
	}
	return (0);
}

