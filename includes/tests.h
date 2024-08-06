#ifndef _TESTS_H
#define	_TESTS_H

#include <errno.h>
#include <sys/types.h>

ssize_t test_write(int fd, const void *buf, size_t count);
ssize_t test_read(int fd, void *buf, size_t count);

#endif