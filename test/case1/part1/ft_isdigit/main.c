/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:55:04 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/18 00:55:05 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <ctype.h>

extern int	ft_isdigit(int c);

int	main(void)
{
	const int	start = 0;
	const int	end = UCHAR_MAX;
	int			err;
	int			i;

	err = (!ft_isdigit(EOF) != !isdigit(EOF));
	i = start;
	while (i <= end)
	{
		err |= (!ft_isdigit(i) != !isdigit(i));
		i++;
	}
	return (err);
}
