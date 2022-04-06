/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_part2_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/06 22:09:35 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strndup(char *src, int max_len)
{
	int		length;
	char	*result;
	char	*tmp;

	tmp = src;
	length = 0;
	while (*tmp++ && length++ < max_len)
		;
	result = (char *) malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	tmp = result;
	length = 0;
	while (*src && length++ < max_len)
		*tmp++ = *src++;
	*tmp = '\0';
	return (result);
}

static char	*ft_string_find_one_of(char *str, char *charset)
{
	char	*tmp;

	str--;
	while (*++str)
	{
		tmp = charset - 1;
		while (*++tmp)
			if (*tmp == *str)
				return (str);
	}
	return (str);
}

static char	*ft_string_find_not_one_of(char *str, char *charset)
{
	char	*tmp;

	str--;
	while (*++str)
	{
		tmp = charset - 1;
		while (*++tmp)
			if (*tmp == *str)
				break ;
		if (!*tmp)
			return (str);
	}
	return (str);
}

static int	ft_split_internal_alloc(char *str, char *charset, char ***out)
{
	char	**result;
	int		length;

	length = 0;
	str = ft_string_find_not_one_of(str, charset);
	while (*str)
	{
		length++;
		str = ft_string_find_one_of(str, charset);
		if (!*str)
			break ;
		str = ft_string_find_not_one_of(str, charset);
	}
	result = malloc(sizeof(char *) * (length + 1));
	if (!result)
		return (1);
	result[length] = NULL;
	*out = result;
	return (0);
}

char	**ft_split(char *str, char c)
{
	char	**result;
	char	*tmp;
	int		index;
	char	charset[2];

	charset[0] = c;
	charset[1] = '\0';
	if (ft_split_internal_alloc(str, charset, &result))
		return (NULL);
	index = 0;
	str = ft_string_find_not_one_of(str, charset);
	while (*str)
	{
		tmp = ft_string_find_one_of(str, charset);
		result[index++] = ft_strndup(str, tmp - str);
		if (!*tmp)
			break ;
		str = ft_string_find_not_one_of(tmp, charset);
	}
	return (result);
}
