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

	err = (!ft_isalnum(EOF) != !isalnum(EOF));
	i = start;
	while (i <= end)
	{
		err |= (!ft_isalnum(i) != !isalnum(i));
		i++;
	}
	return (err);
}
