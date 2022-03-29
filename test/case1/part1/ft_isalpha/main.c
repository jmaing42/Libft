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

	err = (!ft_isascii(EOF) != !isascii(EOF));
	i = start;
	while (i <= end)
	{
		err |= (!ft_isascii(i) != !isascii(i));
		i++;
	}
	return (err);
}
