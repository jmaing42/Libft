/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:17:33 by Juyeong Maing    ###   ########.fr       */
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
	int			tmp;

	if (!n)
		return (ft_strdup("0"));
	len = 0;
	tmp = n;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if (sgn < 0)
		len++;
	result = (char *) malloc(len + 1);
	if (!result)
		return (NULL);
	if (sgn < 0)
		result[0] = '-';
	result[len] = '\0';
	itoa_internal(n, sgn, result + len);
	return (result);
}
