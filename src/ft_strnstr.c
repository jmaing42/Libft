/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/31 16:06:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t len)
{
	const char	*tmp;
	size_t		result;

	result = 0;
	tmp = str - 1;
	while (*++tmp && result < len)
		result++;
	return (result);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const size_t	needle_len = ft_strnlen(to_find, len);
	size_t			max_len;
	size_t			i;

	if (to_find[needle_len])
		return (NULL);
	max_len = ft_strnlen(str, len);
	if (max_len > len)
		max_len = len;
	i = 0;
	while (i + needle_len <= max_len)
	{
		if (ft_memcmp(str + i, to_find, needle_len) == 0)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
