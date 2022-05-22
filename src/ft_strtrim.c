/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/23 02:11:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"

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
