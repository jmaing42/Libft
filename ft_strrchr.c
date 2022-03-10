/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/09 15:43:31 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*result;
	char	to_find;

	to_find = c;
	if (!to_find)
		return ((char *)str + ft_strlen(str));
	result = NULL;
	str--;
	while (*++str)
		if (*str == to_find)
			result = (char *) str;
	return (result);
}
