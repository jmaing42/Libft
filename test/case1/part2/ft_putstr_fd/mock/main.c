/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:55:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/18 00:55:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "write_mock.h"

#define BUFFER_SIZE 1024
#define TEST_COUNT 5
#define PARTIAL_SIZE 42

extern void		ft_putstr_fd(char *str, int fd);

static void		start(const void *buf, size_t size, size_t partial);
static bool		ok(void);

static char			g_buffer[BUFFER_SIZE];
static char			g_buffer_copy[BUFFER_SIZE];

int	test(size_t length, bool test_partial)
{
	const int	fd = rand() % 5 * 42;
	size_t		i;

	i = 0;
	while (i < length)
	{
		g_buffer[i] = (char)(unsigned char)(rand() % (126 - 32 + 1) + 32);
		i++;
	}
	g_buffer[i] = '\0';
	memcpy(g_buffer_copy, g_buffer, length);
	if (test_partial)
		start(g_buffer_copy, length, BUFFER_SIZE / 42);
	else
		start(g_buffer_copy, length, 0);
	ft_putstr_fd(g_buffer_copy, fd);
	return (!ok() || memcmp(g_buffer_copy, g_buffer, length));
}

int	main(void)
{
	int		err;
	size_t	i;
	size_t	length;

	err = 0;
	i = 0;
	while (i < TEST_COUNT)
	{
		length = i * (BUFFER_SIZE - 1) / (TEST_COUNT - 1);
		err |= test(length, false);
		err |= test(length, true);
		i++;
	}
	return (err);
}

static const void	*g_expected;
static size_t		g_expected_length;
static size_t		g_current_offset;
static bool			g_current_failure;
static size_t		g_partial_every;

static ssize_t	write_mock(
					int fd,
					const void *buf,
					size_t size,
					ssize_t (*real_write)(
						int fd, const void *buf, size_t length)
					);

static void	start(const void *buf, size_t size, size_t partial)
{
	g_expected = buf;
	g_expected_length = size;
	g_current_offset = 0;
	g_current_failure = false;
	g_partial_every = partial;
	set_write_mock(write_mock);
}

static ssize_t	write_mock(
	int fd,
	const void *buf,
	size_t size,
	ssize_t (*real_write)(int fd, const void *buf, size_t size)
)
{
	size_t	next_partial_offset;
	size_t	result;

	if (fd % 42)
		return (real_write(fd, buf, size));
	if (!size || g_current_offset + size > g_expected_length)
		g_current_failure = true;
	else if (memcmp((const char *) g_expected + g_current_offset, buf, size))
		g_current_failure = true;
	if (g_current_failure)
		return (-1);
	if (!g_partial_every)
		result = size;
	else
	{
		next_partial_offset = (
				g_current_offset / g_partial_every + 1) * g_partial_every;
		result = next_partial_offset - g_current_offset;
		if (result > size)
			result = size;
	}
	g_current_offset += result;
	return (result);
}

static bool	ok(void)
{
	const bool	result = (
			!g_current_failure
			&& g_expected_length == g_current_offset);

	set_write_mock(NULL);
	return (result);
}
