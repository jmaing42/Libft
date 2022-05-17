/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:13:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char	*result;
	char		to_find;

	result = NULL;
	to_find = (char) c;
	if (!to_find)
		result = str + ft_strlen(str);
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
	return ((char *) result);
}
