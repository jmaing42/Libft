/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/09 16:03:10 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strncmp(const char *a, const char *b, size_t len)
{
	len++;
	while (--len && *a && *b)
	{
		if (*a != *b)
			break ;
		a++;
		b++;
	}
	if (!len)
		return (0);
	return ((int) *((unsigned char *) a) - *((unsigned char *) b));
}
