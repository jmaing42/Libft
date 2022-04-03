#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

extern int	ft_atoi(const char *str);

static const int	g_length = 3;
static const int	g_start[3] = {INT_MIN, -10, INT_MAX - 20};
static const int	g_end[3] = {INT_MIN + 20, 10, INT_MAX};

static const char	*g_formats[] = {
	"%d", "\t%d", "\n%d", "\v%d", "\f%d", "\r%d", " %d", "  %d", "%dx", " %d 0",
	"%+d ", "+%+d", "-%+d", " %+d", " +%+d", " -%+d ", "x%d", "x%015d ", "0%+d",
	"- %d", "+ %d", "0 %d", "%d 0", "%d_0", "0x%d", "%x", "0%x", " %x", "0b0%d",
	"\r\n %+015d", "+%+015d ", "-%+015d ", " %+015d ", " +%+015d ", " -%+015d ",
	"x%+015d", "x %+015d", " \x80%d", " %d\x80", " \xFF%d", " %d\xFF", "\x7F%dx"
};

int	test(int n)
{
	char	str[20];
	int		err;
	size_t	i;

	err = 0;
	i = 0;
	while (i < sizeof(g_formats) / sizeof(g_formats[0]))
	{
		snprintf(str, sizeof(str), g_formats[i], n);
		err |= (ft_atoi(str) != atoi(str));
		if (ft_atoi(str) != atoi(str))
			printf("input: \"%s\", result: %d, expected: %d\n",
				str, ft_atoi(str), atoi(str));
		i++;
	}
	return (err);
}

int	main(void)
{
	int		err;
	int		i;
	int		j;

	err = 0;
	i = 0;
	while (i < g_length)
	{
		j = g_start[i];
		while (j <= g_end[i])
		{
			err |= test(j);
			if (j == INT_MAX)
				break ;
			j++;
		}
		i++;
	}
	return (err);
}
