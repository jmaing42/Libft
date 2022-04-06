#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ft.h"

#define BUFFER_SIZE 1024

char	g_buffer[BUFFER_SIZE];

int	main(void)
{
	char	**result;
	char	**tmp;
	char	separator;

	while (true)
	{
		printf("Enter string to trim: ");
		if (scanf("%1023[^\n]", g_buffer) != 1)
			break ;
		getchar();
		printf("Enter separator: ");
		if (scanf("%c", &separator) != 1)
			break ;
		getchar();
		result = ft_split(g_buffer, separator);
		tmp = result;
		while (tmp && *tmp)
		{
			printf("result: \"%s\"\n", *tmp);
			free(*tmp++);
		}
		free(result);
	}
	return (0);
}
