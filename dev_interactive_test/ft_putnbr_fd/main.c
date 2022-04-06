#include <stdio.h>
#include <stdlib.h>

#include "ft.h"

int	main(void)
{
	int		input;

	while (scanf("%d", &input) == 1)
	{
		ft_putnbr_fd(input, 1);
		putchar('\n');
	}
	return (0);
}
