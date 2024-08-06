#ifndef _TESTS_H
#define	_TESTS_H

#include <errno.h>
#include <sys/types.h>

int	test_strlen(const char *s);
int test_write(int fd, const void *buf, size_t count);
int test_read(int fd, void *buf, size_t count);

#endif