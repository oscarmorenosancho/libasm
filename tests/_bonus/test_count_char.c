#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static int	test_count_char(const char *ts)
{
	int		ret;
	size_t	len;
	size_t	i;


	len = ft_strlen(ts);

	printf(GRN_COL"\nUsing string \"%s\""RST_COL"\n", ts);
	for (i = 0; i < len; i++)
	{
		printf(GRN_COL"\tUsing ft_count_char for arg \'%c\'\n"RST_COL, ts[i]);
		ret = ft_count_char(ts, ts[i]);
		printf("\t\'%c\': is repeated %d times\n", ts[i], ret );
	}
	return (0);
}

int	test_count_char_act(void)
{
	int	ret;

	print_test_header("ft_count_char");

	ret = test_count_char("qwertyQWERTYr YY");
	return (ret);
}