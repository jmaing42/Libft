/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:18:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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
