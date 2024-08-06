#include <stdio.h>
#include <libasm.h>
#include <string.h>

int	test_strlen(const char *s)
{
	size_t	ret;

	printf("Using ft_strlen\n");
	ret = ft_strlen(s);
	printf("counted chars in %s: %zu\n", s, ret);

	printf("Using strlen\n");
	ret = strlen(s);
	printf("counted chars in %s: %zu\n", s, ret);
	return (0);
}
