/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:54:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 19:50:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TEST_COUNT 4242

extern void	*ft_memchr(const void *str, int c, size_t len);

int	main(void)
{
	unsigned int	i;
	size_t			j;
	size_t			k;
	unsigned char	buffer[BUFFER_SIZE];

	i = 0;
	while (i++ < TEST_COUNT)
	{
		srand(i);
		j = 0;
		while (j < BUFFER_SIZE)
			buffer[j++] = rand() % UCHAR_MAX + 1;
		j = rand() % (BUFFER_SIZE / 2);
		k = rand() % (BUFFER_SIZE - j);
		if (ft_memchr((const char *)(&buffer[j]),
			(char)((i * i) % (UCHAR_MAX)), k + 1)
			!= memchr((const char *)(&buffer[j]),
			(char)((i * i) % (UCHAR_MAX)), k + 1))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
