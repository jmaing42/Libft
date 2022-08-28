/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:55:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/28 15:45:18 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "../../../common/leak_test/include/ft/leak_test.h"

#define BUFFER_SIZE 1024
#define TEST_COUNT 5
#define PARTIAL_SIZE 42

extern char	**ft_split(const char *str, char c);

static void	ft_split_free(char	**null_terminated_strings)
{
	char	**tmp;

	tmp = null_terminated_strings;
	while (tmp && *tmp)
		free(*tmp++);
	free(null_terminated_strings);
}

typedef struct s_ft_split_args
{
	const char	*str;
	char		c;
}	t_ft_split_args;

bool	test(const t_ft_split_args *args)
{
	leak_test_start();
	ft_split_free(ft_split(args->str, args->c));
	leak_test_end();
	return (false);
}

int	main(void)
{
	t_ft_split_args	args;
	int				result;
	bool			has_error;

	has_error = false;
	args.c = ' ';
	args.str = "Hello world!";
	result = leak_test((t_leak_test)(&test), &args, NULL);
	if (result != FT_LEAK_TEST_RESULT_OK)
	{
		printf("Failed on '%c' (%s): %s\n",
			args.c, args.str, leak_test_error(result));
		has_error = true;
	}
	if (has_error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
