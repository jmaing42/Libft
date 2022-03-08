/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:39:25 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/08 14:08:49 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	ft_memset(void *mem, int value, size_t len);
int		ft_bzero(void *mem, size_t len);
int		ft_memcpy(void *dest, void *source, size_t len);
int		ft_memmove(void *dest, void *source, size_t len);
int		ft_strlcpy(char *dest, char *source, size_t dest_size);
int		ft_strlcat(char *dest, char *source, size_t dest_size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(int str, char to_find);
char	*ft_strrchr(int str, char to_find);
int		ft_strncmp(char *a, char *b, size_t len);
int		ft_memchr(const void *str, int to_find, size_t len);
int		ft_memcmp(const void *a, const void *b, size_t len);
int		ft_strnstr(char *str, char *to_find);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t item_size);
char	*strdup(const char *str);

#endif
