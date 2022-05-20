/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:54:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 19:35:56 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <ctype.h>

extern int	ft_tolower(int c);

int	main(void)
{
	const int	start = 0;
	const int	end = UCHAR_MAX;
	int			err;
	int			i;

	err = (!ft_tolower(EOF) != !tolower(EOF));
	i = start;
	while (i <= end)
	{
		err |= (!ft_tolower(i) != !tolower(i));
		i++;
	}
	return (err);
}
