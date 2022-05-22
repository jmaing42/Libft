/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/22 19:57:17 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*result;

	str_len = ft_strlen(str + start);
	if (str_len > len)
		str_len = len;
	result = (char *) malloc(str_len + 1);
	if (!result)
		return (NULL);
	result[str_len] = '\0';
	ft_memcpy(result, str + start, str_len);
	return (result);
}
