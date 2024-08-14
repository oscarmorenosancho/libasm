#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_create_elem(char *data)
{
	t_list	*n1;

	print_test_header("ft_create_elem");

	printf(GRN_COL"\tUsing ft_create_elem for arg \'%s\'\n"RST_COL, data);
	n1 = ft_create_elem(data);
	if (n1)
	{
		printf("\tnode content data is: \"%s\"  next points to: %p\n", (char*)n1->data, n1->next);
		free (n1);
	}
	else
	{
		printf("\tfail to create element");
		perror(RED_COL"Error"RST_COL);
	}
	return (0);
}
