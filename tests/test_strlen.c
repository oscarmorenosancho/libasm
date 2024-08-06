#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

int	test_strlen(const char *s)
{
	size_t	ret;

	printf(GRN_COL"\nUsing ft_strlen\n"RST_COL);
	ret = ft_strlen(s);
	printf("counted chars in %s: %zu\n", s, ret);

	printf(BLU_COL"\nUsing strlen\n"RST_COL);
	ret = strlen(s);
	printf("counted chars in %s: %zu\n", s, ret);
	return (0);
}
