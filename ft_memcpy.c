/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/08 21:17:55 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
