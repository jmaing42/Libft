/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:14:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t len)
{
	char	*src;
	char	*dst;

	src = (char *) source;
	dst = (char *) dest;
	while (len--)
		*dst++ = *src++;
	return (dest);
}
