#include <limits.h>
#include <ctype.h>

#include "../../ft.h"

int	main(void)
{
	const int	start = 0;
	const int	end = UCHAR_MAX;
	int			err;
	int			i;

	err = 0;
	i = start;
	while (i <= end)
	{
		err |= (ft_isdigit(i) != isdigit(i));
		i++;
	}

	return (err);
}
