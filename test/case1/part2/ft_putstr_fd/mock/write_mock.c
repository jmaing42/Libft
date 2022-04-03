#include "top_defines.h"

#include <dlfcn.h>
#include <unistd.h>

#include "write_mock.h"

static t_write_mock	g_current_mock;

void	set_write_mock(t_write_mock mock)
{
	g_current_mock = mock;
}

ssize_t	write(int fd, const void *buf, size_t size)
{
	static ssize_t	(*real_write)(int fd, const void *buf, size_t size) = NULL;

	if (!real_write)
	{
		real_write = (ssize_t (*)(int fd, const void *buf, size_t size))
			dlsym(RTLD_NEXT, "write");
		if (!real_write)
		{
			return (-1);
		}
	}
	if (g_current_mock)
		return (g_current_mock(fd, buf, size, real_write));
	else
		return (real_write(fd, buf, size));
}
