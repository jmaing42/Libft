/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:41:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/18 01:41:34 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <ctype.h>

char	g_chars_allowed[SCHAR_MAX + 1];

int	main(void)
{
	char	c;
	int		i;

	i = -1;
	while (++i <= SCHAR_MAX)
		g_chars_allowed[i] = (i == '\n' || i == '\t' || isprint(i));
	while (scanf("%c", &c) == 1)
		if (!g_chars_allowed[(signed char) c])
			return (-1);
	return (0);
}
