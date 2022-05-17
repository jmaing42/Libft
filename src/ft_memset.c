/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:14:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "libft.h"

void	*ft_memset(void *mem, int value, size_t len)
{
	char	*ptr;

	ptr = (char *) mem;
	while (len--)
		*ptr++ = (signed char) value;
	return (mem);
}
