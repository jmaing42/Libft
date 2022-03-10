/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/10 22:53:03 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/* assert(sizeof(int) == 4) */
int	ft_atoi(const char *str)
{
	int			sgn;
	int			result;

	result = 0;
	sgn = 1;
	if (*str == '-')
	{
		str++;
		sgn = -1;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str < '9')
		result = result * 10 + (*str - '0') * sgn;
	return (result);
}
