/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:54:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 19:57:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TEST_COUNT 4242

extern char	*ft_strchr(const void *str, int c);

int	main(void)
{
	unsigned int	i;
	size_t			j;
	unsigned char	buffer[BUFFER_SIZE];

	i = 0;
	while (i++ < TEST_COUNT)
	{
		srand(i);
		j = 0;
		while (j + 1 < BUFFER_SIZE)
			buffer[j++] = rand() % UCHAR_MAX + 1;
		buffer[j] = '\0';
		j = rand() % (BUFFER_SIZE - 1);
		if (ft_strchr((const char *)(&buffer[j]),
			(char)((i * i) % (UCHAR_MAX)))
			!= strchr((const char *)(&buffer[j]),
			(char)((i * i) % (UCHAR_MAX))))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
