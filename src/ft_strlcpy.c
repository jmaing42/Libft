/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/08 22:39:02 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft.h"

size_t	ft_strlcpy(char *dest, char *source, size_t dest_size)
{
	unsigned int	i;

	if (!dest_size)
	{
		i = 0;
		while (*source++)
		{
			i++;
		}
		return (i);
	}
	dest_size--;
	i = 0;
	while (*source && i < dest_size)
	{
		i++;
		*dest++ = *source++;
	}
	*dest = '\0';
	while (*source++)
	{
		i++;
	}
	return (i);
}
