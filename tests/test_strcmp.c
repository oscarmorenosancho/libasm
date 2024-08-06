#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

int	test_strcmp(const char *s1, const char *s2)
{
	int	ret;

	printf(GRN_COL"\nUsing ft_strcmp\n"RST_COL);
	ret = ft_strcmp(s1, s2);
	printf("comparison between %s and %s: %d\n", s1, s2, ret);

	printf(BLU_COL"\nUsing strcmp\n"RST_COL);
	ret = strcmp(s1, s2);
	printf("comparison between %s and %s: %d\n", s1, s2, ret);
	return (0);
}