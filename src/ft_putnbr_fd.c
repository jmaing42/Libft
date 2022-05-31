/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/31 16:06:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

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
		ft_putchar_fd('0', fd);
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
