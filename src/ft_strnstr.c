/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/14 12:56:52 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const size_t	needle_len = ft_strlen(to_find);
	size_t			max_len;
	size_t			i;

	max_len = ft_strlen(str);
	if (max_len > len)
		max_len = len;
	i = 0;
	while (i + needle_len <= max_len)
	{
		if (ft_memcmp(str + i, to_find, needle_len) == 0)
			return ((char *) str + i);
		i++;
	}
	return (NULL);
}
