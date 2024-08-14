#include <stdio.h>
#include <tests.h>

void	print_test_header(const char *title)
{
	printf(GRN_COL"\n============================\n"RST_COL);
	printf(GRN_COL"TEST %s\n"RST_COL, title);
	printf(GRN_COL"============================\n"RST_COL);	
}
	