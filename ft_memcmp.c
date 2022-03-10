/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/09 16:12:33 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	len++;
	while (--len)
	{
		if (*a != *b)
			return ((int) *((unsigned char *) a) - *((unsigned char *) b));
		a++;
		b++;
	}
	return (0);
}
