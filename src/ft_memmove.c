/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/15 05:05:40 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft.h"

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
