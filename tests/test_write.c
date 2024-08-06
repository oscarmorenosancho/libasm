#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <unistd.h>



int test_write(int fd0, int fd1, const void *buf, size_t count)
{
	ssize_t	ret;

	printf(GRN_COL"\nUsing ft_write from buf %p with fd %d"RST_COL"\n", buf,fd0);
	ret = ft_write(fd0, buf, count);
	if (ret < 0)
		perror(RED_COL"Error"RST_COL);
	else
		printf("written chars: %zd\n", ret);

	printf(BLU_COL"\nUsing write from buf %p with fd %d"RST_COL"\n", buf, fd1);
	ret = write(fd1, buf, count);
	if (ret < 0)
		perror(RED_COL"Error"RST_COL);
	else
		printf("written chars: %zd\n", ret);
	return (0);
}