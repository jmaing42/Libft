/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/14 14:11:27 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	len++;
	while (--len && *a && *b)
	{
		if (*a != *b)
			break ;
		a++;
		b++;
	}
	if (!len)
		return (0);
	return ((int) *a - *b);
}
