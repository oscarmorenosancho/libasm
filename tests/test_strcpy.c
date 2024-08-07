#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

int 	test_strcpy(char *dest, const char *src)
{
	char	*ret;

	ret = NULL;
	dest[0]=0;
	printf(GRN_COL"\nUsing ft_strcpy\n"RST_COL);
	printf("before copy:\n\tdestination is %p \"%s\",\n\tsource is %p \"%s\"\n", dest, dest, src, src);
	ret = ft_strcpy(dest, src);
	printf("after copy:\n\tdestination is %p \"%s\",\n\tsource is %p \"%s\"\n", dest, dest, src, src);

	ret = NULL;
	dest[0]=0;
	printf(BLU_COL"\nUsing strcpy\n"RST_COL);
	printf("before copy:\n\tdestination is %p \"%s\",\n\tsource is %p \"%s\"\n", dest, dest, src, src);
	ret = strcpy(dest, src);
	printf("after copy:\n\tdestination is %p \"%s\",\n\tsource is %p \"%s\"\n", dest, dest, src, src);
	return (0);
}