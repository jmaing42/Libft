#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

extern int	ft_atoi(const char *str);

static const int	g_length = 3;
static const int	g_start[3] = {INT_MIN, -10, INT_MAX - 20};
static const int	g_end[3] = {INT_MIN + 20, 10, INT_MAX};

static const char	*g_formats[] = {
	"%zd", "\t%zd", "\n%zd", "\v%zd", "\f%zd", "\r%zd", " %zd", "  %zd", "%zdx",
	"%+zd ", "+%+zd", "-%+zd", " %+zd", " +%+zd", " -%+zd ", "x%zd", "x%015zd ",
	"- %zd", "+ %zd", "%zd 0", "%zd_0", "0x%zd", "%zx", "0%zx", " %zx", " %zx0",
	"%+015zd", "+%+015zd ", "-%+015zd ", " %+015zd ", " +%+015zd ", " -%+015zd",
	"x%+015zd", "x %+015zd", "\x80%zd", "%zd\x80", "\xFF%zd", "%zd\xFF", "x%zdx"
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
