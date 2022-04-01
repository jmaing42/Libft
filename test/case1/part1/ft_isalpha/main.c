#include <stdio.h>
#include <limits.h>
#include <ctype.h>

extern int ft_isalpha(int c);

int	main(void)
{
	const int	start = 0;
	const int	end = UCHAR_MAX;
	int			err;
	int			i;

	err = (!ft_isalpha(EOF) != !isalpha(EOF));
	i = start;
	while (i <= end)
	{
		err |= (!ft_isalpha(i) != !isalpha(i));
		i++;
	}
	return (err);
}
