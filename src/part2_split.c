/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/15 09:23:06 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ft.h"

static void	ft_array_free(char **arr)
{
	char	**tmp;

	tmp = arr - 1;
	while (*++tmp)
		free(tmp);
	free(arr);
}

static char	*ft_strndup(const char *src, size_t max_len)
{
	size_t	length;
	char	*result;
	char	*tmp;

	tmp = *((char **)((void *) &src));
	length = 0;
	while (*tmp++ && length++ < max_len)
		;
	result = malloc(length + 1);
	if (!result)
		return (NULL);
	tmp = result;
	length = 0;
	while (*src && length++ < max_len)
		*tmp++ = *src++;
	*tmp = '\0';
	return (result);
}

static const char	*ft_string_find(const char *str, char c, bool inverse)
{
	str--;
	while (*++str)
		if ((*str != c) != inverse)
			return (str);
	return (str);
}

static int	ft_split_internal_alloc(const char *str, char c, char ***out)
{
	char	**result;
	size_t	length;

	length = 0;
	str = ft_string_find(str, c, true);
	while (*str)
	{
		length++;
		str = ft_string_find(str, c, false);
		if (!*str)
			break ;
		str = ft_string_find(str, c, true);
	}
	result = calloc(length + 1, sizeof(char *));
	if (!result)
		return (1);
	result[length] = NULL;
	*out = result;
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char		**result;
	const char	*tmp;
	size_t		index;

	if (ft_split_internal_alloc(str, c, &result))
		return (NULL);
	index = 0;
	str = ft_string_find(str, c, true);
	while (*str)
	{
		tmp = ft_string_find(str, c, false);
		result[index] = ft_strndup(str, (uintptr_t) tmp - (uintptr_t) str);
		if (!result[index])
		{
			ft_array_free(result);
			return (NULL);
		}
		index++;
		if (!*tmp)
			break ;
		str = ft_string_find(tmp, c, true);
	}
	return (result);
}
