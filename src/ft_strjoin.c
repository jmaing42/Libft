/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:20:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	const size_t	prefix_len = ft_strlen(prefix);
	const size_t	suffix_len = ft_strlen(suffix);
	char *const		result = (char *) malloc(prefix_len + suffix_len + 1);

	if (!result)
		return (NULL);
	ft_memcpy(result, prefix, prefix_len);
	ft_memcpy(result + prefix_len, suffix, suffix_len);
	result[prefix_len + suffix_len] = '\0';
	return (result);
}