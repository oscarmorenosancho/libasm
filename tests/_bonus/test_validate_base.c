#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static int	test_validate_base(const char *base)
{
	int	ret;

	printf(GRN_COL"\tUsing ft_validate_base for arg \"%s\"\n"RST_COL, base);
	ret = ft_validate_base(base);
	printf("\tbase \"%s\": %s\n", base, ret ? "is valid" : "is NOT valid");
	return (0);
}

int	test_validate_base_act()
{
	print_test_header("ft_validate_base");

	test_validate_base("01");
	test_validate_base("0123456789");
	test_validate_base("0123456789abcdef");
	test_validate_base("!@#$^&*()[]{}%=\\/~|.,?");
	test_validate_base("QWERTY");
	test_validate_base("ABCXYZ");
	test_validate_base("01234567895");
	test_validate_base("0123456789+");
	test_validate_base("0123456789-");
	test_validate_base("0123456789 ");
	test_validate_base("0123456789\t");
	test_validate_base("0123456789\n");
	test_validate_base("qwertyQWERTY");
	test_validate_base("abcxyzABCXYZ");
	test_validate_base("");
	test_validate_base("0");
	test_validate_base(NULL);
	return (0);
}
