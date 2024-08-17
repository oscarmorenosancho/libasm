#include <stdio.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

static const char	*strs[] = { "10000000000000000000000000000000", \
							"1000000000000000 ", \
							"FFFFFFFFFFFFFFFF", \
							"0F0F0F0F0F0F0F0F", \
							"15", "FF", "8", "F", \
							"", "--15x", "FFq", "+--+8x", \
							"Fx", "x", \
							\
							"-1000000000000000 ", \
							"-FFFFFFFFFFFFFFFF", \
							"-0F0F0F0F0F0F0F0F", \
							"--+-15", "-FF", "-8", "-F", \
							"-", "-+--+15x", "-FFq", "--+--+-8x", \
							"-Fx", "-x", \
							NULL };

static const int	bin_exp[] = { 0b10000000000000000000000000000000, \
							0b1000000000000000, \
							0b0, \
							0b0, \
							0b1, 0b0, 0b0, 0b0, \
							0b0, 0b1, 0b0, 0b0, \
							0b0, 0b0, \
							\
							0b11111111111111111000000000000000, \
							0b0, \
							0b0, \
							-1, 0b0, 0b0, 0b0, \
							0b0, -1, 0b0, 0b0, \
							0b0, 0b0, \
							0b0 };

static const int	dec_exp[] = { -2147483648, \
							-1530494976, \
							0, \
							0, \
							15, 0, 8, 0, \
							0, 15, 0, 8, \
							0, 0, \
							\
							1530494976, \
							0, \
							0, \
							-15, 0, -8, 0, \
							0, -15, 0, -8, \
							0, 0, \
							0 };

static const int	hex_exp[] = { 0x0, 
							0x0, \
							0xFFFFFFFF, \
							0x0F0F0F0F, \
							0x15, 0xFF, 0x8, 0xF, \
							0x0, 0x15, 0xFF, 0x8, \
							0xF, 0x0, \
							\
							0x0, \
							0x1, \
							0xf0f0f0f1, \
							0xffffffeb, 0xffffff01, 0xfffffff8, 0xfffffff1, \
							0x0, 0xffffffeb, 0xffffff01, 0xfffffff8, \
							0xfffffff1, 0x0, \
							0x0 };

static const char	bin_base[] = "01";
static const char	dec_base[] = "0123456789";
static const char	hex_base[] = "0123456789ABCDEF";

static int		test_atoi_base(char *str, const char *base, int expect)
{
	int		res;
	int		ret;

	printf(GRN_COL"\tUsing ft_atoi_base for arg \"%s\" and base \"%s\"\n"RST_COL, str, base);
	ret = ft_atoi_base(str, (char*)base);
	res = (ret != expect);
	printf("\tbin is: 0b");
	print_binary_int(ret);
	printf(" vs\n\texpected: 0b");
	print_binary_int(expect);
	printf("\n");
	printf("\tdec is: %d vs\n\texpected: %d\n", ret, expect);
	printf("\thex is: 0x%x vs\n\texpected: 0x%x\n", ret, expect);
	print_test_result(res);
	return (res);
}

int		test_atoi_base_act()
{
	size_t		i;
	int			res;
	
	print_test_header("ft_atoi_base");
	(void)hex_base;
	(void)dec_base;
	(void)bin_base;
	(void)hex_exp;
	(void)dec_exp;
	(void)bin_exp;

	res = 0;
	i = 0;
	while (strs[i])
	{
		printf("index in table %zu\n", i);
		res += test_atoi_base((char*)strs[i], bin_base, bin_exp[i]);
		res += test_atoi_base((char*)strs[i], dec_base, dec_exp[i]);
		res += test_atoi_base((char*)strs[i], hex_base, hex_exp[i]);
		i++;
	}
	return (res);
}