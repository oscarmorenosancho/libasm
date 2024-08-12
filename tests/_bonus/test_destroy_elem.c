#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

int		test_destroy_elem(t_list *node, void (*free_fct)(void *))
{
	printf(GRN_COL"Using ft_destroy_elem for args node: %p free_fct: %p'\n"RST_COL, node, free_fct);
	if (!node)
		printf(RED_COL"Using ft_destroy_elem needs a node to destroy'\n"RST_COL);
	ft_destroy_elem(node, free_fct);
	printf("After ft_destroy_elem'\n" );
	return	(0);
}

int		test_destroy_elem_examples()
{
	t_list	*node;
	char	*content;

	(void)node;
	(void)content;
	printf(GRN_COL"Test to destroy a NULL node"RST_COL);
	test_destroy_elem(NULL, NULL);
	
	printf(GRN_COL"Test to craeate a node with static content and destroy it"RST_COL"\n");
	node = ft_create_elem("static content");
	test_destroy_elem(node, NULL);	

	printf(GRN_COL"Test to craeate a node with alloc'ed content and destroy it"RST_COL"\n");
	content = strdup("alloc'ed content");
	node = ft_create_elem(content);
	test_destroy_elem(node, free);	

	return	(0);
}
