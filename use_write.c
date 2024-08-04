int ft_write(unsigned int fd, char *buf, long int count);

int main(void)
{
	ft_write(1, "Hello World!\n", 13);
	return 0;
}

