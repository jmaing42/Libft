#ifndef WRITE_MOCK_H
# define WRITE_MOCK_H

# include <unistd.h>

typedef ssize_t	(*t_write_mock)(
	int fd,
	const void *buf,
	size_t size,
	ssize_t (*real_write)(int fd, const void *buf, size_t size));

void	set_write_mock(t_write_mock mock);

#endif
