#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

int	test_strcmp(const char *s1, const char *s2)
{
	int	ret;

	print_test_header("ft_strcmp");

	printf(GRN_COL"\nUsing ft_strcmp\n"RST_COL);
	ret = ft_strcmp(s1, s2);
	printf("comparison between %s and %s: %d\n", s1, s2, ret);

	printf(BLU_COL"\nUsing strcmp\n"RST_COL);
	ret = strcmp(s1, s2);
	printf("comparison between %s and %s: %d\n", s1, s2, ret);
	return (0);
}

int	test_strcmp_examples(void)
{
	static const char *hw = "Hello World!\n";
	static const char *hw2 = "Hello World! to stderr\n";
	static const char *tab = "\ttabulated\n";

	test_strcmp("", "");	
	test_strcmp("a", "a");	
	test_strcmp("a", "b");	
	test_strcmp("b", "a");	
	test_strcmp("hw2", "hw");	
	test_strcmp("hw*", "hw");	
	test_strcmp("hw", "hw*");	
	test_strcmp(tab, hw);	
	test_strcmp(hw2, hw);
	return (0);
}