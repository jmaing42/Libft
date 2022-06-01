/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/01 20:59:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __cplusplus
# include <cstdlib>
#else
# include <stdlib.h>
#endif

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
