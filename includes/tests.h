#ifndef _TESTS_H
#define	_TESTS_H

#define BLK_COL "\033[31m"
#define RED_COL "\033[31m"
#define GRN_COL "\033[32m"
#define ORG_COL "\033[33m"
#define BLU_COL "\033[34m"
#define MAG_COL "\033[35m"
#define CYN_COL "\033[36m"
#define RST_COL	"\033[0m"

#include <errno.h>
#include <sys/types.h>

void	print_test_header(const char *title);
int		test_strlen(const char *s);
int 	test_strcpy(char *dest, const char *src);
int		test_strcmp(const char *s1, const char *s2);
int 	test_strdup(const char *src);
int		test_write(int fd0, int fd1, const void *buf, size_t count);
int		test_read(int fd0, int fd1, void *buf, size_t count);

int		test_strlen_examples(void);
int 	test_strcpy_examples(void);
int		test_strcmp_examples(void);
int 	test_strdup_examples(void);
int		test_write_examples(void);
int		test_read_examples(void);



#endif