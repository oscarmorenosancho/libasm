#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

static int 	test_strcpy(const char *src)
{
	char 	buf1[1024];
	char 	buf2[1024];
	char	*ret1;
	char	*ret2;
	int		res;

	ret1 = NULL;
	buf1[0]=0;
	printf(GRN_COL"\nUsing ft_strcpy\n"RST_COL);
	printf("before copy:\n\tdestination is %p \"%s\",\n\tsource is %p \"%s\"\n", buf1, buf1, src, src);
	ret1 = ft_strcpy(buf1, src);
	printf("after copy:\n\tdestination is %p \"%s\",\n\tsource is %p \"%s\"\n", buf1, buf1, src, src);

	ret2 = NULL;
	buf2[0]=0;
	printf(BLU_COL"\nUsing strcpy\n"RST_COL);
	printf("before copy:\n\tdestination is %p \"%s\",\n\tsource is %p \"%s\"\n", buf2, buf2, src, src);
	ret2 = strcpy(buf2, src);
	printf("after copy:\n\tdestination is %p \"%s\",\n\tsource is %p \"%s\"\n", buf2, buf2, src, src);

	res = (ret1 != buf1) || (ret2 != buf2) || strcmp(buf1, buf2);

	print_test_result(res);
	return (res);
}

int 	test_strcpy_act(void)
{
	int	ret;
	static const char *plain = "Plain text and some special characters 你好世界! to copy";

	print_test_header("ft_strcpy");
	ret = test_strcpy(plain);	
	ret += test_strcpy("");	
	return (ret);
}
