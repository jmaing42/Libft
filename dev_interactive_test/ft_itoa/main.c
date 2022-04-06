#include <stdio.h>
#include <stdlib.h>

#include "ft.h"

int	main(void)
{
	int		input;
	char	*result;

	while (scanf("%d", &input) == 1)
	{
		result = ft_itoa(input);
		if (!result)
			continue ;
		printf("result: %s\n", result);
		free(result);
	}
	return (0);
}
