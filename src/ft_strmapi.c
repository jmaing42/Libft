/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:18:06 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int index, char c))
{
	char *const		result = ft_strdup(str);
	unsigned int	index;

	if (result)
	{
		index = 0;
		while (result[index])
		{
			result[index] = f(index, result[index]);
			index++;
		}
	}
	return (result);
}
