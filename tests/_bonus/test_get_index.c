#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

// static const char	special[] = "你好世界";
static const char	plain[] = \
	"Plain text and some special characters";
//   0123456789012345678901234567890123456789012345678901234

static const int	plain_loc[] = {0, 1, 2 ,3, 4, 5, 6, 7, 8, 6,\
//								   P  l  a  i  n ' ' t  e  x  t
	5, 2, 4, 13, 5, 15, 16, 17, 7, 5, 15, 21, 7, 23, 3, 2, 1, 5, \
// ' ' a  n   d ' '  s   o   m  e ' ' s   p   e  c   i  a  l ' '
	23, 29, 2, 31, 2, 23, 6,  7, 31, 15 };
//   c   h  a   r  a   c  t   e   r   s

static const char	query[] = "qwertyQWERTYP";

static const int	query_loc[] = \
		{-1, -1, 7 ,31, 6, -1, -1, -1, -1, -1, -1 , -1, 0};
//		 q    w  e   r  t   y   Q   W   E   R   T    Y  P


static int	test_get_index(const char *ts, const char *qs, const int *exp)
{
	ssize_t	ret;
	size_t	len;
	size_t	i;
	int		res;

	res = 0;

	len = ft_strlen(qs);

	printf(GRN_COL"With"RST_COL"\n");
	printf(GRN_COL"\tstring: \"%s\""RST_COL"\n", ts);
	printf(ORG_COL"\tquery: \"%s\""RST_COL"\n\n", qs);
	for (i = 0; i < len; i++)
	{
		printf(GRN_COL"\tUsing ft_get_index for arg \'%c\'\n"RST_COL, qs[i]);
		ret = ft_get_index(ts, qs[i]);
		if (ret != exp[i]) res++;
		printf("\t\'%c\': is located at position %zd, expected: %d\n"\
				, qs[i], ret, exp[i]);
	}
	print_test_result(res);
	return (res);
}

int	test_get_index_act(void)
{
	int	ret;
	print_test_header("ft_get_index");

	ret = 0;
	// test_get_index(plain, "qwertyQWERTYP你");
	ret += test_get_index(plain, plain, plain_loc);
	ret += test_get_index(plain, query, query_loc);
	return (ret);
}