#include <tests.h>
#include <string.h>

static const char *hw = "Hello World!\n";
static const char *hw2 = "Hello World! to stderr\n";
static const char *uc = "Some special characters 你好世界!\n";
static const char *tab = "\ttabulated\n";

int main(void)
{
	test_write(1, hw, strlen(hw));
	test_write(2, hw2, strlen(hw2));
	test_write(1, uc, strlen(uc));
	test_write(1, tab, strlen(tab));
	test_write(10, hw, strlen(hw));
	test_write(1, NULL, 10);
	test_write(1, hw, 120);
	test_write(1, "\n", 1);
	return (0);
}

