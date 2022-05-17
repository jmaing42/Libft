/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:13:03 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	len++;
	while (--len)
	{
		if (*a != *b)
			return ((int) *a - *b);
		a++;
		b++;
	}
	return (0);
}
