/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_part2_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/31 13:08:35 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	size_t	len;
	ssize_t	wrote;

	len = ft_strlen(str);
	while (len)
	{
		wrote = write(fd, str, len);
		if (wrote < 0)
			return ;
		len -= (size_t) wrote;
		str = str + wrote;
	}
}

void	ft_putendl_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}

static void	putnbr_internal(int n, int fd, int sgn)
{
	if (n / 10)
		putnbr_internal(n / 10, fd, sgn);
	ft_putchar_fd((char)('0' + sgn * (n % 10)), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!n)
	{
		ft_putnbr_fd('0', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		putnbr_internal(n, fd, -1);
	}
	else
	{
		putnbr_internal(n, fd, 1);
	}
}
