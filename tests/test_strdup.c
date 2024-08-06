#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

int 	test_strdup(const char *src)
{
	char	*ret;

	ret = NULL;
	printf(GRN_COL"\nUsing ft_strdup\n"RST_COL);
	printf("before dup: return is %p\n", ret);
	printf("before dup: destination is %s, \nsource is %s\n", ret, src);
	ret = ft_strdup(src);
	printf("after dup: destination is %s, \nsource is %s\n", ret, src);
	printf("after dup: return is %p\n", ret);
	if (ret)
		free(ret);

	ret = NULL;
	printf(BLU_COL"\nUsing strdup\n"RST_COL);
	printf("before dup: return is %p\n", ret);
	printf("before dup: destination is %s, \nsource is %s\n", ret, src);
	ret = strdup(src);
	printf("after dup: destination is %s, \nsource is %s\n", ret, src);
	printf("after dup: return is %p\n", ret);
	if (ret)
		free(ret);
	return (0);
}