#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

char 	*test_strcpy(char *dest, const char *src)
{
	char	*ret;

	ret = NULL;
	dest[0]=0;
	printf(GRN_COL"\nUsing ft_strcpy\n"RST_COL);
	printf("before copy: destination ponter is %p, return is %p\n", dest, ret);
	printf("before copy: destination is %s, \nsource is %s\n", dest, src);
	ret = ft_strcpy(dest, src);
	printf("after copy: destination is %s, \nsource is %s\n", dest, src);
	printf("after copy: destination ponter is %p, return is %p\n", dest, ret);

	ret = NULL;
	dest[0]=0;
	printf(BLU_COL"\nUsing strcpy\n"RST_COL);
	printf("before copy: destination ponter is %p, return is %p\n", dest, ret);
	printf("before copy: destination is %s, \nsource is %s\n", dest, src);
	ret = strcpy(dest, src);
	printf("after copy: destination is %s, \nsource is %s\n", dest, src);
	printf("after copy: destination ponter is %p, return is %p\n", dest, ret);
	return (0);
}