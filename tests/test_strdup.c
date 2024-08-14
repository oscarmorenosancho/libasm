#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

int 	test_strdup(const char *src)
{
	char	*ret;

	print_test_header("ft_strdup");

	ret = NULL;
	printf(GRN_COL"\nUsing ft_strdup\n"RST_COL);
	printf("before dup:\n\treturn is %p \"%s\",\n\tsource is %p \"%s\"\n", ret, ret, src, src);
	ret = ft_strdup(src);
	printf("after dup:\n\treturn is %p \"%s\",\n\tsource is %p \"%s\"\n", ret, ret, src, src);
	if (ret)
		free(ret);

	ret = NULL;
	printf(BLU_COL"\nUsing strdup\n"RST_COL);
	printf("before dup:\n\treturn is %p \"%s\",\n\tsource is %p \"%s\"\n", ret, ret, src, src);
	ret = strdup(src);
	printf("after dup:\n\treturn is %p \"%s\",\n\tsource is %p \"%s\"\n", ret, ret, src, src);
	if (ret)
		free(ret);
	return (0);
}

int 	test_strdup_examples(void)
{
	static const char *plain = "Plain text and some special characters 你好世界! to copy";

	test_strdup(plain);	
	return (0);
}

