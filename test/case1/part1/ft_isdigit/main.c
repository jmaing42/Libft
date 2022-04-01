#include <stdio.h>
#include <limits.h>
#include <ctype.h>

extern int ft_isdigit(int c);

int	main(void)
{
	const int	start = 0;
	const int	end = UCHAR_MAX;
	int			err;
	int			i;

	err = (!ft_isdigit(EOF) != !isdigit(EOF));
	i = start;
	while (i <= end)
	{
		err |= (!ft_isdigit(i) != !isdigit(i));
		i++;
	}
	return (err);
}
