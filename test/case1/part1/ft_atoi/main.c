/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:54:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/18 00:54:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "test.h"

extern int	ft_atoi(const char *str);

static const int	g_length = 3;
static const int	g_start[3] = {INT_MIN, -10, INT_MAX - 20};
static const int	g_end[3] = {INT_MIN + 20, 10, INT_MAX};

int	main(void)
{
	const char	*err;
	size_t		i;
	size_t		j;

	err = 0;
	i = 0;
	while (i < g_length)
	{
		j = g_start[i];
		while (j <= g_end[i])
		{
			err = test(j, ft_atoi, atoi);
			if (err)
			{
				printf("test failed - input: \"%s\", %d\n", err, j);
				return (EXIT_FAILURE);
			}
			if (j == INT_MAX)
				break ;
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
