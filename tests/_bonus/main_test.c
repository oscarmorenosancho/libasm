#include <tests.h>
#include <tests_bonus.h>
#include <string.h>

// static const char *hw = "Hello World!\n";
// static const char *hw2 = "Hello World! to stderr\n";
// static const char *uc = CYN_COL"Some special characters 你好世界!\n"RST_COL;
// static const char *tab = "\ttabulated\n";
static const char *plain = "Plain text and some special characters 你好世界! to copy";

int main(void)
{
	(void)plain;
	// t_list	*l1 = NULL;
	// char	*content = "content";

	// test_isspace();
	// test_count_char("qwertyQWERTYr YY");
	// test_get_index(plain, "qwertyQWERTYP你");
	// test_validate_base_examples();
	// test_trim_spaces_examples();
	// test_get_sign_examples();
	// test_atoui_base_examples();
	// test_atoi_base_examples();

	// test_create_elem(content);
	// test_list_push_front(&l1, content);

	test_list_size_examples();
	// test_destroy_elem_examples();
	// test_list_pop_examples();
	// test_list_remove_front_examples();
	// test_list_remove_if_examples();

	// char buf[128];
	// (void) hw;
	// (void) hw2;
	// (void) uc;
	// (void) tab;
	// (void) plain;

	// test_strlen(uc);

	// test_strcpy(buf, plain);	

	// test_strdup(plain);	

	// test_strcmp("", "");	
	// test_strcmp("a", "a");	
	// test_strcmp("a", "b");	
	// test_strcmp("b", "a");	
	// test_strcmp("hw2", "hw");	
	// test_strcmp("hw*", "hw");	
	// test_strcmp("hw", "hw*");	
	// test_strcmp(tab, hw);	
	// test_strcmp(hw2, hw);	

	// test_write(1, 1, hw, strlen(hw));
	// test_write(2, 2, hw2, strlen(hw2));
	// test_write(1, 1, uc, strlen(uc));
	// test_write(1, 1, tab, strlen(tab));
	// test_write(10, 10, hw, strlen(hw));
	// test_write(1, 1, NULL, 10);
	// test_write(1, 1, hw, 120);
	// test_write(1, 1, "\n", 1);

	// test_read(0, 0, buf, 1);
	// test_read(10, 10, buf, 1);
	// test_read(0, 0, NULL, 1);

	return (0);
}

