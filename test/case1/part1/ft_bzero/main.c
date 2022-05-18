/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:54:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/18 09:23:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TEST_COUNT 4242

extern void	ft_bzero(void *mem, size_t len);

int	main(void)
{
	unsigned int	i;
	size_t			j;
	size_t			k;
	unsigned char	buffer[BUFFER_SIZE];
	unsigned char	copy[BUFFER_SIZE];

	i = 0;
	while (i++ < TEST_COUNT)
	{
		srand(i);
		j = 0;
		while (j < BUFFER_SIZE)
			buffer[j++] = rand() % (1 << CHAR_BIT);
		memcpy(copy, buffer, BUFFER_SIZE);
		j = rand() % (BUFFER_SIZE / 2);
		k = rand() % (BUFFER_SIZE - j);
		ft_bzero(buffer + j, k + 1);
		bzero(copy + j, k + 1);
		if (memcmp(buffer, copy, BUFFER_SIZE))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
