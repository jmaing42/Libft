/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/10 22:40:37 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static size_t	min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const size_t	needle_len = ft_strlen(to_find);
	const size_t	max_len = min(ft_strlen(str), len);
	size_t			i;

	i = 0;
	while (i + needle_len <= max_len)
	{
		if (ft_memcmp(str + i, to_find, needle_len) == 0)
			return ((char *) str + i);
		i++;
	}
	return (NULL);
}
