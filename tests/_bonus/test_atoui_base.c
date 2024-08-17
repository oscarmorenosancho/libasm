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
							"", "15x", "FFx", "8x", \
							"Fx", "x", NULL };

static const long	bin_exp[] = { 0b10000000000000000000000000000000, \
							0b1000000000000000, \
							0b0, \
							0b0, \
							0b1, 0b0, 0b0, 0b0, \
							0b0, 0b1, 0b0, 0b0, \
							0b0, 0b0, 0b0 };

static const long	dec_exp[] = { -4570789518076018688, \
							1000000000000000, \
							0, \
							0, \
							15, 0, 8, 0, \
							0, 15, 0, 8, \
							0, 0, 0 };

static const long	hex_exp[] = { 0x0, 
							0x1000000000000000, \
							0xFFFFFFFFFFFFFFFF, \
							0x0F0F0F0F0F0F0F0F, \
							0x15, 0xFF, 0x8, 0xF, \
							0x0, 0x15, 0xFF, 0x8, \
							0xF, 0x0, 0x0 };

static const char	bin_base[] = "01";
static const char	dec_base[] = "0123456789";
static const char	hex_base[] = "0123456789ABCDEF";

static void		print_binary(long value)
{
	int i;
	int len = sizeof (long) * 8;
	char buf[len + 1];
	long cur;

	cur = value;
	for (i = 0; i < len; i++)
	{
		buf[len - i - 1] = (cur & 1)? '1' : '0';
		cur >>= 1; 
	}
	buf[len] = 0;
	printf("%s", buf);
}


static int		test_atoui_base(char *str, const char *base, long expect)
{
	int		res;
	long	ret;

	printf(GRN_COL"\tUsing ft_atoui_base for arg \"%s\" and base \"%s\"\n"RST_COL, str, base);
	ret = ft_atoui_base(str, (char*)base);
	res = (ret != expect);
	printf("\tbin is: 0b");
	print_binary(ret);
	printf(" vs\n\texpected: 0b");
	print_binary(expect);
	printf("\n");
	printf("\tdec is: %ld vs\n\texpected: %ld\n", ret, expect);
	printf("\thex is: 0x%lx vs\n\texpected: 0x%lx\n", ret, expect);
	print_test_result(res);
	return (res);
}

int		test_atoui_base_act()
{
	size_t		i;
	int			res;
	
	print_test_header("ft_atoui_base");
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
		res += test_atoui_base((char*)strs[i], bin_base, bin_exp[i]);
		res += test_atoui_base((char*)strs[i], dec_base, dec_exp[i]);
		res += test_atoui_base((char*)strs[i], hex_base, hex_exp[i]);
		i++;
	}
	return (res);
}
