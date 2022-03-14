/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/14 14:05:30 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strchr(const char *str, int c)
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
