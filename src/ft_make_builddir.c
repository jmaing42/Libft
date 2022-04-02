/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_builddir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:10:03 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/02 17:20:39 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

void	make_common_print_header(void);
void	make_common_print_variable(const char *name, const char *value);
void	make_common_print_rule(
			bool phony,
			const char *name,
			const char *dependencies,
			const char *recipe
			);

typedef void	(*t_v)(const char *name, const char *value);
typedef void	(*t_r)(
	bool phony,
	const char *name,
	const char *dependencies,
	const char *recipe
);

void	variables(void)
{
	const t_v	v = make_common_print_variable;

	v("SRC_DIR", "..");
	v("AR", "ar");
	v("CC", "clang");
	v("CFLAGS", "-Wall -Wextra -Werror");
	v("NAME_BONUS", "bonus.a");
	v("NAME_BASIC", "basic.a");
	v("SRCS_BONUS", "$(addprefix $(SRC_DIR)/,$(filter ft_src_%.c,$(SRCS)))");
	v("SRCS_BASIC", "$(filter-out $(addprefix $(SRC_DIR)/," \
							"$(filter ft_src_%.c,$(SRCS))), $(SRCS_BONUS))");
	v("SRC_PATH_PREFIX", "$(SRC_DIR)/ft_src_");
	v("OBJS_BONUS", "$(patsubst $(SRC_PATH_PREFIX)%.c,%.o,$(SRCS_BONUS))");
	v("OBJS_BASIC", "$(patsubst $(SRC_PATH_PREFIX)%.c,%.o,$(SRCS_BASIC))");
	v("DEPS", "$(OBJS_BONUS:.o=.d)");
}

void	base_rules(void)
{
	const t_r	r = make_common_print_rule;

	r(true, "all", "$(NAME_BASIC) $(NAME_BONUS)", NULL);
	r(false, "$(NAME_BASIC)", "$(OBJS_BASIC)",
		"$Qrm -f $@\n" \
		"$Q$(AR) cr $@ $^\n" \
		"");
	r(false, "$(NAME_BONUS)", "$(OBJS_BONUS)",
		"$Qrm -f $@\n" \
		"$Q$(AR) cr $@ $^\n" \
		"");
	r(false, "%.o", "$(SRC_PATH_PREFIX)%.c",
		"$Q$(CC) $(CFLAGS) -c $< -o $@ -MMD\n" \
		"");
	puts("-include $(DEPS)");
}

void	tested_rules(void)
{
	const t_r	r = make_common_print_rule;

	r(true, "test", "test_basic test_bonus", NULL);
	r(false,
		"test_basic test_bonus: test_%",
		"%.a tester_common_% tester_only_%",
		"$Q./$(patsubst test_%,tester_common_%,$@)\n" \
		"$Q./$(patsubst test_%,tester_only_%,$@)\n" \
		"");
	puts(".PHONY: test_basic test_bonus");
	r(false, "%_tested.a", "%.a", "" \
		"$Q$(MAKE) $(patsubst %_tested.a,test_%,$@)\n" \
		"$Qcp $(@:_tested.a=.a) $@\n" \
		"");
}

void	tester_rules(void)
{
	const t_r	r = make_common_print_rule;

	r(false, "tester_common_%", "tester_common.a %.a",
		"$Qgcc -o $@ -Wall -Wextra -Werror $^");
	r(false, "tester_only_%", "tester_%.a %.a",
		"$Qgcc -o $@ -Wall -Wextra -Werror $^");
	r(false, "tester_%.a", NULL,
		"$Q$Q$(MAKE) builddir_$(@:.a=)\n" \
		"$Q$Q$(MAKE) -C builddir_$(@:.a=)\n" \
		"$Qcp builddir_$(@:.a=)/tester.a $@\n" \
		"$Qrm -rf builddir_$(@:.a=)\n" \
		"");
	puts(".PRECIOUS: tester_%.a");
	r(false, "builddir_tester_%", NULL,
		"$Qrm -rf tmp/$@\n" \
		"$Qmkdir -p tmp/$@\n" \
		"$Qgcc -Wall -Wextra -Werror -o tmp/$@/makegen " \
			"$(SRC_DIR)/ft_make_$@.c $(SRC_DIR)/ft_make_common.c\n" \
		"$Qtmp/$@/makegen > tmp/$@/Makefile\n" \
		"$Qrm -f tmp/$@/makegen\n" \
		"$Qmv tmp/$@ .\n" \
		"");
}

int	main(void)
{
	make_common_print_header();
	variables();
	base_rules();
	tested_rules();
	tester_rules();
	return (0);
}
