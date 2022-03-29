#include <limits.h>
#include <ctype.h>

#include "../../ft.h"

int	main(void)
{
	const int	start = -UCHAR_MAX;
	const int	end = UCHAR_MAX * 2;
	int			err;
	int			i;

	err = 0;
	i = start;
	while (i <= end)
	{
		err |= (ft_isalnum(i) != isalnum(i));
		i++;
	}
	return (err);
}
