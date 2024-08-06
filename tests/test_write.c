# include <stdio.h>
#include <libasm.h>
#include <unistd.h>

int test_write(int fd, const void *buf, size_t count)
{
	int	ret;

	printf("Using ft_write\n");
	ret = ft_write(fd, buf, count);
	if (ret < 0)
	{
		perror("Error");
		return (ret);
	}
	printf("written chars: %d\n", ret);

	printf("Using write\n");
	ret = write(fd, buf, count);
	if (ret < 0)
	{
		perror("Error");
		return (ret);
	}
	printf("written chars: %d\n", ret);
	return (0);
}