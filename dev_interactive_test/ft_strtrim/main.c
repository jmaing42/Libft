#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ft.h"

#define BUFFER_SIZE 1024

char	g_buffer_1[BUFFER_SIZE];
char	g_buffer_2[BUFFER_SIZE];

int	main(void)
{
	char	*result;

	while (true)
	{
		printf("Enter string to trim: ");
		if (scanf("%1023[^\n]", g_buffer_1) != 1)
			break ;
		getchar();
		printf("Enter separator set: ");
		if (scanf("%1023[^\n]", g_buffer_2) != 1)
			break ;
		getchar();
		result = ft_strtrim(g_buffer_1, g_buffer_2);
		if (!result)
			continue ;
		printf("input (str): \"%s\"\n", g_buffer_1);
		printf("input (sep): \"%s\"\n", g_buffer_2);
		printf("result: \"%s\"\n", result);
		free(result);
	}
	return (0);
}
