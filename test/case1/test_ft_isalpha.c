/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:33:13 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/26 05:33:15 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <ft.h>

#include "main.h"

int	test_ft_isalpha_c(const char *kind)
{
	char	c;
	int		expected_result;
	int		actual_result;

	scanf(",%c", &c);
	scanf(",%d", &expected_result);
	actual_result = ft_isalpha(c);
	if (actual_result != expected_result)
		printf("%s: input: %c, result: %d, expected: %d\n",
			kind, c, actual_result, expected_result);
	return (actual_result != expected_result);
}

int	test_ft_isalpha_i(const char *kind)
{
	int	c;
	int	expected_result;
	int	actual_result;

	scanf(",%i", &c);
	scanf(",%d", &expected_result);
	actual_result = ft_isalpha(c);
	if (actual_result != expected_result)
		printf("%s: input: %d, result: %d, expected: %d\n",
			kind, c, actual_result, expected_result);
	return (actual_result != expected_result);
}
