/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/09 16:13:48 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	char	to_find;
	char	*mem;

	to_find = c;
	mem = (char *) str;
	mem--;
	while (len--)
		if (*++mem == to_find)
			return ((void *) mem);
	return (NULL);
}
