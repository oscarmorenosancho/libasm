#include <unistd.h>

int ft_write(int fd, char *msg, size_t len)
{
	write(fd, msg, len);
}

int main(void)
{
	int	ret_val;
	ret_val = ft_write(1, "Hello World!\n", 13);
	return (0);
}
