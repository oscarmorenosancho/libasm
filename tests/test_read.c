#include <stdio.h>
#include <libasm.h>
#include <unistd.h>

int test_read(int fd, void *buf, size_t count)
{
	ssize_t	ret;

	printf("Using ft_read\n");
	ret = ft_read(fd, buf, count);
	if (ret < 0)
	{
		perror("Error");
		return (ret);
	}
	((char *)buf)[ret]=0;
	printf("read chars: %zd %s\n", ret, (char *)buf);

	printf("Using read\n");
	ret = read(fd, buf, count);
	if (ret < 0)
	{
		perror("Error");
		return (ret);
	}
	((char *)buf)[ret]=0;
	printf("read chars: %zd %s\n", ret, (char *)buf);
	return (0);
}