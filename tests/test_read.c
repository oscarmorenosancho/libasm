#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <unistd.h>

int test_read(int fd0, int fd1, void *buf, size_t count)
{
	ssize_t	ret;
	char	ext;

	printf(GRN_COL"\nUsing ft_read to buf %p with fd %d"RST_COL"\n", buf, fd0);
	ret = ft_read(fd0, buf, count);
	if (ret < 0)
		perror(RED_COL"Error"RST_COL);
	else
	{
		((char *)buf)[ret]=0;
		printf("read chars: %zd %s\n", ret, (char *)buf);
	}
	while( ((ret = ft_read(fd0, &ext, 1) ) > 0) && ext!='\n');

	printf(BLU_COL"\nUsing read to buf %p with fd %d"RST_COL"\n", buf, fd1);
	ret = read(fd1, buf, count);
	if (ret < 0)
		perror(RED_COL"Error"RST_COL);
	else
	{
		((char *)buf)[ret]=0;
		printf("read chars: %zd %s\n", ret, (char *)buf);
	}
	while( ((ret = read(fd0, &ext, 1) ) > 0) && ext!='\n');
	return (0);
}

int test_read_examples(void)
{
	char buf[128];

	print_test_header("ft_read");

	test_read(0, 0, buf, 1);
	test_read(10, 10, buf, 1);
	test_read(0, 0, NULL, 1);
	return (0);
}