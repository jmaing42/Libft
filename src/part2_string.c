/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/15 08:07:52 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*result;

	str_len = ft_strlen(&str[start]);
	if (str_len > len)
		str_len = len;
	result = malloc(str_len + 1);
	if (!result)
		return (NULL);
	result[str_len] = '\0';
	ft_memcpy(result, &(*((char **)((void *) &str)))[start], str_len);
	return (result);
}

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	const size_t	prefix_len = ft_strlen(prefix);
	const size_t	suffix_len = ft_strlen(suffix);
	char			*result;

	result = malloc(prefix_len + suffix_len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, *((char **)((void *) &suffix)), prefix_len);
	ft_memcpy(&result[prefix_len], *((char **)((void *) &suffix)), suffix_len);
	result[prefix_len + suffix_len] = '\0';
	return (result);
}

static size_t	str_count_consecutive_set(
	const char *from,
	const char *set,
	bool inverse,
	int direction)
{
	size_t		result;
	const char	*tmp;
	bool		found;

	result = 0;
	while (from[(intptr_t) result * direction])
	{
		found = false;
		tmp = set - 1;
		while (*++tmp)
			if (*tmp == from[(intptr_t) result * direction])
				found = true;
		if (found == inverse)
			break ;
		result++;
	}
	return (result);
}

char	*ft_strtrim(char const *str, char const *ignore_set)
{
	size_t	len;
	size_t	ignore;
	char	*result;

	str = &str[str_count_consecutive_set(str, ignore_set, false, 1)];
	len = ft_strlen(str);
	if (!len)
		return (ft_strdup(""));
	ignore = str_count_consecutive_set(&str[len - 1], ignore_set, false, -1);
	result = malloc(len - ignore + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, *((char **)((void *) &str)), len - ignore);
	result[len - ignore] = '\0';
	return (result);
}

char	**ft_split(char const *str, char c);
// TODO: implement ft_split
