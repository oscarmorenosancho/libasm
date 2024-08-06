#include <tests.h>
#include <string.h>

static const char *hw = "Hello World!\n";
static const char *hw2 = "Hello World! to stderr\n";
static const char *uc = CYN_COL"Some special characters 你好世界!\n"RST_COL;
static const char *tab = "\ttabulated\n";
static const char *plain = "\"Plain text and some special characters 你好世界! to copy\"";

int main(void)
{
	char buf[128];

	test_strlen(uc);

	test_strcpy(buf, plain);	

	test_write(1, 1, hw, strlen(hw));
	test_write(2, 2, hw2, strlen(hw2));
	test_write(1, 1, uc, strlen(uc));
	test_write(1, 1, tab, strlen(tab));
	test_write(10, 10, hw, strlen(hw));
	test_write(1, 1, NULL, 10);
	test_write(1, 1, hw, 120);
	test_write(1, 1, "\n", 1);

	test_read(0, 0, buf, 1);
	test_read(10, 10, buf, 1);
	test_read(0, 0, NULL, 1);

	return (0);
}

