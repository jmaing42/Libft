/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/01 20:58:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __cplusplus
# include <climits>
#else
# include <limits.h>
#endif
#include <unistd.h>

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	remain;
	size_t	to_write;
	ssize_t	wrote;

	remain = ft_strlen(str);
	while (remain)
	{
		to_write = remain;
		if (to_write > SSIZE_MAX)
			to_write = SSIZE_MAX;
		wrote = write(fd, str, to_write);
		if (wrote < 0)
			return ;
		remain -= (size_t) wrote;
		str = str + wrote;
	}
}
