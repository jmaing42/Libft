/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/15 06:58:23 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "ft.h"

void	ft_bzero(void *mem, size_t len)
{
	ft_memset(mem, 0, len);
}

void	*ft_memset(void *mem, int value, size_t len)
{
	char	*ptr;

	ptr = (char *) mem;
	while (len--)
		*ptr++ = (signed char) value;
	return (mem);
}

void	*ft_memcpy(void *dest, void *source, size_t len)
{
	char	*src;
	char	*dst;

	src = (char *) source;
	dst = (char *) dest;
	while (len--)
		*dst++ = *src++;
	return (dest);
}

void	*ft_memmove(void *dest, void *source, size_t len)
{
	char	*src;
	char	*dst;

	if (dest < source || (uintptr_t) source + len < (uintptr_t) dest)
		return (ft_memcpy(dest, (void *) source, len));
	src = (char *) source + len;
	dst = (char *) dest + len;
	while (len--)
		*dst-- = *src--;
	return (dest);
}

void	*ft_calloc(size_t count, size_t item_size)
{
	return (malloc(count * item_size));
}
