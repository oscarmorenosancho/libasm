#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int	test_trim_spaces(const char *str)
{
	char		*trimmed;

	printf(GRN_COL"\tUsing ft_trim_spaces for arg \"%s\"\n"RST_COL, str);
	trimmed = ft_trim_spaces(str);
	printf("\toriginal string: \"%s\"\n\t trimmed string: \"%s\"\n", str, trimmed);
	return (0);
}

int	test_trim_spaces_examples()
{
	size_t		i;
	char		*strs[] = {"  abcde", "abcde", "", " ", " 01", "\t01", NULL};

	test_trim_spaces(NULL);
	i = 0;
	while (strs[i])
	{
		test_trim_spaces(strs[i]);
		i++;
	}
	return (0);
}