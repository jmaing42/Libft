/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/01 20:58:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __cplusplus
# include <cstdint>
#else
# include <stdint.h>
#endif

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t len)
{
	char	*src;
	char	*dst;

	if (dest < source || (uintptr_t) source + len < (uintptr_t) dest)
		return (ft_memcpy(dest, (void *) source, len));
	src = (char *) source + len;
	dst = (char *) dest + len;
	while (len--)
		*--dst = *--src;
	return (dest);
}
