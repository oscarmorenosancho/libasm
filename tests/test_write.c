#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <unistd.h>
#include <string.h>



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

int test_write_examples(void)
{
	const char *hw = "Hello World!\n";
	const char *hw2 = "Hello World! to stderr\n";
	const char *uc = CYN_COL"Some special characters 你好世界!\n"RST_COL;
	const char *tab = "\ttabulated\n";

	print_test_header("ft_write");

	test_write(1, 1, hw, strlen(hw));
	test_write(2, 2, hw2, strlen(hw2));
	test_write(1, 1, uc, strlen(uc));
	test_write(1, 1, tab, strlen(tab));
	test_write(10, 10, hw, strlen(hw));
	test_write(1, 1, NULL, 10);
	test_write(1, 1, hw, 120);
	test_write(1, 1, "\n", 1);
	return (0);
}
