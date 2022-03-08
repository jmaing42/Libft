/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/08 22:39:09 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft.h"

size_t	ft_strlcat(char *dest, char *source, size_t dest_size)
{
	unsigned int	length;

	length = 0;
	while (dest_size && *dest)
	{
		length++;
		dest++;
		dest_size--;
	}
	return (length + ft_strlcpy(dest, source, dest_size));
}
