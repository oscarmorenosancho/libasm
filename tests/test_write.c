#include <stdio.h>
#include <string.h>
#include <libasm.h>
#include <tests.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

static char openw_fail_msg[] = RED_COL"Open failed to create and open file"RST_COL"\n";
static char openr_fail_msg[] = RED_COL"Open failed to read file"RST_COL"\n";
static char f_to_std[] = "testf_write.txt";
static char f_to_mine[] = "testf_ft_write.txt";
static	int wflags = O_CREAT | O_WRONLY | O_TRUNC;
static	int rflags = O_RDONLY;
static	int mode = S_IRUSR | S_IWUSR;

static	int test_write_to_file(const void *buf, size_t count)
{
	int		res;
	ssize_t	ret[5];
	int		fd[2];
	char	rbuf[2][1024];

	printf(GRN_COL"Compare result of write vs ft_write\n"RST_COL);
	ret[4] = count;
	fd[0] = open(f_to_mine, wflags, mode);
	fd[1] = open(f_to_std, wflags, mode);
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror(openw_fail_msg);
		return (1);
	}
	ret[0] = ft_write(fd[0], buf, count);
	ret[1] = write(fd[1], buf, count);
	close(fd[0]);
	close(fd[1]);
	fd[0] = open(f_to_mine, rflags, mode);
	fd[1] = open(f_to_std, rflags, mode);
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror(openr_fail_msg);
		return (1);
	}
	ret[2] = read(fd[0], rbuf[0], count+10);
	if (ret[2] >= 0) rbuf[0][ret[2]] = 0; 
	ret[3] = read(fd[1], rbuf[1], count+10);
	if (ret[3] >= 0) rbuf[1][ret[3]] = 0; 
	close(fd[0]);
	close(fd[1]);
	res = ret[4] != ret[0] || ret[4] != ret[1];
	res = res || ret[4] != ret[2] || ret[4] != ret[3];
	res = res || strcmp(rbuf[0],rbuf[1]);
	printf("Read of written in file by ft_write:\n\"%s\"\n", rbuf[0]);
	printf("Read of written in file by write:\n\"%s\"\n", rbuf[1]);
	print_test_result (res);
	return (res);
}

int test_write(int fd0, int fd1, const void *buf, size_t count)
{
	int		res;
	ssize_t	ret;

	res = 0;
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
	return (res);
}

int test_write_examples(void)
{
	int	ret;
	const char *hw = "Hello World!\n";
	const char *hw2 = "Hello World! to stderr\n";
	const char *uc = CYN_COL"Some special characters 你好世界!\n"RST_COL;
	const char *tab = "\ttabulated\n";

	print_test_header("ft_write");

	ret = test_write(1, 1, hw, strlen(hw));
	ret += test_write(2, 2, hw2, strlen(hw2));
	ret += test_write(1, 1, uc, strlen(uc));
	ret += test_write(1, 1, tab, strlen(tab));
	ret += test_write(10, 10, hw, strlen(hw));
	ret += test_write(1, 1, NULL, 10);
	ret += test_write(1, 1, hw, 120);
	ret += test_write(1, 1, "\n", 1);
	ret += test_write_to_file(hw, strlen(hw));
	ret += test_write_to_file(hw2, strlen(hw2));
	ret += test_write_to_file(uc, strlen(uc));
	ret += test_write_to_file(tab, strlen(tab));
	remove(f_to_mine);
	remove(f_to_std);
	return (ret);
}
