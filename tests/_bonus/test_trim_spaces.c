#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>
#include <ctype.h>

static char		*strs[] = {"  abcde", \
						"abcde", \
						"\f\nwith other type of spaces", \
						"\v\rwith other type of spaces", \
						"", \
						" ", \
						" 01", \
						"\t01" \
						, NULL};

static int	test_trim_spaces(const char *str)
{
	int		res;
	char	*trimmed;

	printf(GRN_COL"Using ft_trim_spaces for arg \"%s\""RST_COL"\n\n", str);
	trimmed = ft_trim_spaces(str);
	printf(RST_COL"\toriginal string: \"%s\""RST_COL"\n", str);
	printf(ORG_COL"\t trimmed string: \"%s\""RST_COL"\n", trimmed);
	res = 0;
	if (trimmed && !trimmed[0])
		res = isspace(trimmed[0]);
	print_test_result(res);
	return (res);
}

int	test_trim_spaces_act()
{
	int			ret;
	size_t		i;

	print_test_header("ft_trim_spaces");

	test_trim_spaces(NULL);
	i = 0;
	ret = 0;
	while (strs[i])
	{
		ret += test_trim_spaces(strs[i]);
		i++;
	}
	return (ret);
}