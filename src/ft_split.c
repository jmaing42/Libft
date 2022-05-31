/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/31 16:06:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

static char	*ft_strndup(const char *src, size_t max_len)
{
	size_t		length;
	char		*result;
	const char	*tmp;
	char		*temp;

	tmp = src;
	length = 0;
	while (*tmp++ && ++length < max_len)
		;
	result = (char *) malloc(length + 1);
	if (!result)
		return (NULL);
	temp = result;
	length = 0;
	while (*src && length++ < max_len)
		*temp++ = *src++;
	*temp = '\0';
	return (result);
}

static const char	*ft_string_find_one_of(
	const char *str,
	const char *charset,
	bool negate
)
{
	const char	*tmp;

	str--;
	while (*++str)
	{
		tmp = charset - 1;
		if (negate)
		{
			while (*++tmp)
				if (*tmp == *str)
					break ;
			if (!*tmp)
				return (str);
		}
		else
		{
			while (*++tmp)
				if (*tmp == *str)
					return (str);
		}
	}
	return (str);
}

static int	ft_split_internal_alloc(
	const char *str,
	const char *charset,
	char ***out
)
{
	char	**result;
	size_t	length;

	length = 0;
	str = ft_string_find_one_of(str, charset, true);
	while (*str)
	{
		length++;
		str = ft_string_find_one_of(str, charset, false);
		if (!*str)
			break ;
		str = ft_string_find_one_of(str, charset, true);
	}
	result = (char **) malloc(sizeof(char *) * (length + 1));
	if (!result)
		return (1);
	result[length] = NULL;
	*out = result;
	return (0);
}

static void	ft_split_free(char	**null_terminated_strings)
{
	char	**tmp;

	tmp = null_terminated_strings;
	while (*tmp)
		free(*tmp++);
	free(tmp);
}

char	**ft_split(const char *str, char c)
{
	char		**result;
	size_t		index;
	bool		alloc_failed;
	const char	*tmp;
	const char	charset[2] = {c, '\0'};

	alloc_failed = false;
	if (ft_split_internal_alloc(str, charset, &result))
		return (NULL);
	index = 0;
	str = ft_string_find_one_of(str, charset, true);
	while (*str)
	{
		tmp = ft_string_find_one_of(str, charset, false);
		result[index] = ft_strndup(str, tmp - str);
		if (!result[index++])
			alloc_failed = true;
		if (!*tmp || alloc_failed)
			break ;
		str = ft_string_find_one_of(tmp, charset, true);
	}
	if (!alloc_failed)
		return (result);
	ft_split_free(result);
	return (NULL);
}
