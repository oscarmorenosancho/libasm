#ifndef _TESTS_BONUS_H
#define	_TESTS_BONUS_H

#include <errno.h>
#include <sys/types.h>

int		test_strlen(const char *s);
int 	test_strcpy(char *dest, const char *src);
int		test_strcmp(const char *s1, const char *s2);
int 	test_strdup(const char *src);
int		test_write(int fd0, int fd1, const void *buf, size_t count);
int		test_read(int fd0, int fd1, void *buf, size_t count);

#endif