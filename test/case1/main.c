#include <stdio.h>
#include <string.h>

#include "main.h"

#define BUFFER_SIZE 1024

typedef struct s_tuple__static_string__func_i_ {
	const char	*name;
	int			(*test)(const char *kind);
}	t_tuple__static_string__func_i_;

char							g_buffer_kind[1024];
t_tuple__static_string__func_i_	g_tests[] = {
	{"ft_isalpha_c", test_ft_isalpha_c},
	{"ft_isalpha_i", test_ft_isalpha_i},
};

int	main(void)
{
	size_t							i;
	int								err;
	t_tuple__static_string__func_i_	*test;

	err = 0;
	while (1)
	{
		if (scanf(" %1000[^\n,]", g_buffer_kind) != 1)
			break ;
		test = NULL;
		i = 0;
		while (i < sizeof(g_tests) / sizeof(g_tests[0]))
		{
			if (strcmp(g_tests[i].name, g_buffer_kind) == 0)
			{
				test = &g_tests[i];
				break ;
			}
			i++;
		}
		if (!test)
			printf("Undefined kind: %s\n", g_buffer_kind);
		err |= !test || test->test(g_buffer_kind);
	}
	return (err);
}
