/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/09 15:43:47 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strchr(const char *str, int c)
{
	char	to_find;

	to_find = c;
	if (!to_find)
		return ((char *)str + ft_strlen(str));
	str--;
	while (*++str)
		if (*str == to_find)
			return ((char *) str);
	return (NULL);
}
