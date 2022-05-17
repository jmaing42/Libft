/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:17:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int index, char *inout_c))
{
	unsigned int	index;

	if (str)
	{
		index = 0;
		while (str[index])
		{
			f(index, str + index);
			index++;
		}
	}
}
