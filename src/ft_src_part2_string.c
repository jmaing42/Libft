/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_part2_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/03 12:52:18 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*result;

	str_len = ft_strlen(&str[start]);
	if (str_len > len)
		str_len = len;
	result = (char *) malloc(str_len + 1);
	if (!result)
		return (NULL);
	result[str_len] = '\0';
	ft_memcpy(result, str + start, str_len);
	return (result);
}

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	const size_t	prefix_len = ft_strlen(prefix);
	const size_t	suffix_len = ft_strlen(suffix);
	char *const		result = (char *) malloc(prefix_len + suffix_len + 1);

	if (!result)
		return (NULL);
	ft_memcpy(result, prefix, prefix_len);
	ft_memcpy(result + prefix_len, suffix, suffix_len);
	result[prefix_len + suffix_len] = '\0';
	return (result);
}

static size_t	str_count_consecutive_set(
	const char *from,
	const char *set,
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
		if (!found)
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

	str = str + str_count_consecutive_set(str, ignore_set, 1);
	len = ft_strlen(str);
	if (!len)
		return (ft_strdup(""));
	ignore = str_count_consecutive_set(&str[len - 1], ignore_set, -1);
	result = (char *) malloc(len - ignore + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, str, len - ignore);
	result[len - ignore] = '\0';
	return (result);
}
