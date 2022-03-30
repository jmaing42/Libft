/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part1_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/30 14:02:36 by jmaing           ###   ########.fr       */
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

void	*ft_memchr(const void *str, int c, size_t len)
{
	char		to_find;
	const char	*mem;

	to_find = (char) c;
	mem = str;
	mem--;
	while (len--)
		if (*++mem == to_find)
			return (*((void **)((void *) &mem)));
	return (NULL);
}

char	*ft_strchr(const char *str, int c)
{
	const char	*result;
	char		to_find;

	result = NULL;
	to_find = (char) c;
	if (!to_find)
		result = &str[ft_strlen(str)];
	else
	{
		str--;
		while (*++str)
		{
			if (*str == to_find)
			{
				result = str;
				break ;
			}
		}
	}
	return (*((char **)((void *) &result)));
}

char	*ft_strrchr(const char *str, int c)
{
	const char	*result;
	char		to_find;

	to_find = (char) c;
	if (!to_find)
		result = &str[ft_strlen(str)];
	else
	{
		result = NULL;
		str--;
		while (*++str)
			if (*str == to_find)
				result = str;
	}
	return (*((char **)((void *) &result)));
}
