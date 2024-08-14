#include <string.h>

int		ft_always_equal(const char *s1, const char *s2)
{
	(void)s1;
	(void)s2;
	return (0);
}

int		ft_greater(const char *s1, const char *s2)
{
	return (strcmp(s1, s2));
}

int		ft_lesser(const char *s1, const char *s2)
{
	return (strcmp(s2, s1));
}
