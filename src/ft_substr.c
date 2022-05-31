/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/31 16:06:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*result;

	while (start-- && *str)
		str++;
	str_len = ft_strlen(str);
	if (str_len > len)
		str_len = len;
	result = (char *) malloc(str_len + 1);
	if (!result)
		return (NULL);
	result[str_len] = '\0';
	ft_memcpy(result, str, str_len);
	return (result);
}
