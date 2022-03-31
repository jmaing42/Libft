/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_part2_etc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/31 13:08:27 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

static void	itoa_internal(int n, int sgn, char *dest)
{
	if (n / 10)
		itoa_internal(n / 10, sgn, dest - 1);
	dest[-1] = (char)('0' + sgn * (n % 10));
}

char	*ft_itoa(int n)
{
	const int	sgn = (n >= 0) * 2 - 1;
	char		*result;
	size_t		len;

	if (!n)
		return (ft_strdup("0"));
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	result = (char *) malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	itoa_internal(n, sgn, result + len);
	if (sgn < 0)
		result[0] = '-';
	return (result);
}

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
