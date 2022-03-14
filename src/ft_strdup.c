/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/14 13:16:52 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft.h"

char	*ft_strdup(const char *str)
{
	void	*result;
	size_t	size;

	size = ft_strlen(str) + 1;
	result = malloc(size);
	if (!result)
		return (NULL);
	ft_memcpy(result, (void *) str, size);
	return ((char *) result);
}
