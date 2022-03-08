/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/08 21:41:43 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft.h"

static void	*ft_memrcpy(void *dest, void *source, size_t len)
{
	char	*src;
	char	*dst;

	src = (char *) source + len;
	dst = (char *) dest + len;
	while (len--)
		*dst-- = *src--;
	return (dest);
}

void	*ft_memmove(void *dest, void *source, size_t len)
{
	if (source < dest && (uintptr_t) source + len > (uintptr_t) dest)
		return (ft_memrcpy(dest, (void *) source, len));
	return (ft_memcpy(dest, (void *) source, len));
}
