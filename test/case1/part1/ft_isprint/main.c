#include <stdio.h>
#include <limits.h>
#include <ctype.h>

#include "../../ft.h"

int	main(void)
{
	const int	start = 0;
	const int	end = UCHAR_MAX;
	int			err;
	int			i;

	err = (!ft_isprint(EOF) != !isprint(EOF));
	i = start;
	while (i <= end)
	{
		err |= (!ft_isprint(i) != !isprint(i));
		i++;
	}
	return (err);
}
