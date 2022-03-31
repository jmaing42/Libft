/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_part1_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/31 12:07:57 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*tmp;
	size_t		result;

	result = 0;
	tmp = str - 1;
	while (*++tmp)
		result++;
	return (result);
}

size_t	ft_strlcpy(char *dest, char *source, size_t dest_size)
{
	unsigned int	i;

	if (!dest_size)
	{
		i = 0;
		while (*source++)
			i++;
		return (i);
	}
	dest_size--;
	i = 0;
	while (*source && i < dest_size)
	{
		i++;
		*dest++ = *source++;
	}
	*dest = '\0';
	while (*source++)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, char *source, size_t dest_size)
{
	unsigned int	length;

	length = 0;
	while (dest_size && *dest)
	{
		length++;
		dest++;
		dest_size--;
	}
	return (length + ft_strlcpy(dest, source, dest_size));
}

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
		if (ft_memcmp(&str[i], to_find, needle_len) == 0)
			return (&(*((char **)((void *) &str)))[i]);
		i++;
	}
	return (NULL);
}
