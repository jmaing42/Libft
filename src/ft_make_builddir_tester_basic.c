/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_builddir_tester_basic.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:54:40 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/30 13:26:19 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static const char *const	g_makefile_contents = "" \
	"all: tester.a\n" \
	"tester.a: tester.o\n" \
	"	ar cr tester.a tester.o\n" \
	"tester.o: tester.c\n" \
	"	gcc -o tester.o -Wall -Wextra -Werror -c tester.c\n" \
	"tester.c:\n" \
	"	echo \"" \
				"int main() { return 0; }" \
			"\" > tester.c\n" \
	"";

int	main(void)
{
	printf("%s", g_makefile_contents);
	return (0);
}
