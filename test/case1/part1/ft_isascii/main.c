/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:55:01 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/18 00:55:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <ctype.h>

extern int	ft_isascii(int c);

int	main(void)
{
	const int	start = -UCHAR_MAX;
	const int	end = UCHAR_MAX * 2;
	int			err;
	int			i;

	err = (!ft_isascii(EOF) != !isascii(EOF));
	i = start;
	while (i <= end)
	{
		err |= (!ft_isascii(i) != !isascii(i));
		i++;
	}
	return (err);
}
