#include <stdio.h>
#include <libasm.h>
#include <tests.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


static char openw_fail_msg[] = RED_COL"Open failed to create and open file"RST_COL"\n";
static char openr_fail_msg[] = RED_COL"Open failed to read file"RST_COL"\n";
static char f_to_std[] = "testf_read.txt";
static char f_to_mine[] = "testf_ft_read.txt";
static	int wflags = O_CREAT | O_WRONLY | O_TRUNC;
static	int rflags = O_RDONLY;
static	int mode = S_IRUSR | S_IWUSR;

static	int test_read_from_file(const char *buf, size_t reduce_read)
{
	int		res;
	ssize_t	ret[6];
	int		fd[2];
	char	rbuf[2][1024];

	printf(GRN_COL"Compare result of read vs ft_read\n"RST_COL);
	ret[4] = strlen(buf);
	ret[5] = 0;
	if (reduce_read < (size_t)ret[4])
		ret[5] = ret[4] - reduce_read;
	fd[0] = open(f_to_mine, wflags, mode);
	fd[1] = open(f_to_std, wflags, mode);
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror(openw_fail_msg);
		return (1);
	}
	ret[0] = write(fd[0], buf, ret[4]);
	ret[1] = write(fd[1], buf, ret[4]);
	close(fd[0]);
	close(fd[1]);
	fd[0] = open(f_to_mine, rflags, mode);
	fd[1] = open(f_to_std, rflags, mode);
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror(openr_fail_msg);
		return (1);
	}
	ret[2] = ft_read(fd[0], rbuf[0], ret[5]);
	if (ret[2] >= 0) rbuf[0][ret[2]] = 0; 
	ret[3] = read(fd[1], rbuf[1], ret[5]);
	if (ret[3] >= 0) rbuf[1][ret[3]] = 0; 
	close(fd[0]);
	close(fd[1]);
	res = ret[4] != ret[0] || ret[4] != ret[1];
	res = res || ret[5] != ret[2] || ret[5] != ret[3];
	res = res || strcmp(rbuf[0],rbuf[1]);
	printf(RST_COL"Read with ft_read what's written in file:\n\"%s"RST_COL"\"\n", rbuf[0]);
	printf(RST_COL"Read with read what's written in file:\n\"%s"RST_COL"\"\n", rbuf[1]);
	print_test_result (res);
	return (res);
}

static int test_read(int fd0, int fd1, void *buf, size_t count)
{
	ssize_t	ret;
	char	ext;

	printf(GRN_COL"\nUsing ft_read to buf %p with fd %d"RST_COL"\n", buf, fd0);
	printf(RST_COL"Type something and press ENTER to continue>\n"RST_COL);
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
	printf(RST_COL"Type something and press ENTER to continue>\n"RST_COL);
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

int test_read_act(void)
{
	int			ret;
	char		buf[128];
	const char	*hw = "Hello World!\n";
	const char	*hw2 = "Hello World! longer message longer message";
	const char	*uc = CYN_COL"Some special characters 你好世界!\n"RST_COL;
	const char	*tab = "\ttabulated\n";

	print_test_header("ft_read");

	ret = test_read(0, 0, buf, 1);
	ret += test_read(10, 10, buf, 1);
	ret += test_read(0, 0, NULL, 1);
	ret += test_read_from_file(hw, 0);
	ret += test_read_from_file(hw2, 0);
	ret += test_read_from_file(uc, 0);
	ret += test_read_from_file(tab, 0);
	ret += test_read_from_file(hw, 5);
	ret += test_read_from_file(hw2, 5);
	ret += test_read_from_file(uc, 15);
	ret += test_read_from_file(tab, 5);
	remove(f_to_mine);
	remove(f_to_std);
	return (ret);
}
