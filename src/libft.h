/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:39:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/01 20:42:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifdef __cplusplus
#  include <cstddef>
# else
#  include <stddef.h>
# endif

// [PREPROCESSOR] BONUS PART START

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Part 3 - Singly Linked List
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *node);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// [PREPROCESSOR] BONUS PART END

// Part 1 - Libc functions

# ifdef __cplusplus

extern "C"

# endif

int ft_isalpha(int c);

#  ifdef __cplusplus

extern "C"

# endif

int ft_isdigit(int c);

#   ifdef __cplusplus

extern "C"

# endif

int ft_isalnum(int c);

#    ifdef __cplusplus

extern "C"

# endif

int ft_isascii(int c);

#     ifdef __cplusplus

extern "C"

# endif

int ft_isprint(int c);

#      ifdef __cplusplus

extern "C"

# endif

void ft_bzero(void *mem, size_t len);

#       ifdef __cplusplus

extern "C"

# endif

void *ft_memset(void *mem, int value, size_t len);

#        ifdef __cplusplus

extern "C"

# endif

void *ft_memcpy(void *dest, const void *source, size_t len);

#         ifdef __cplusplus

extern "C"

# endif

void *ft_memmove(void *dest, const void *source, size_t len);

#          ifdef __cplusplus

extern "C"

# endif

void *ft_calloc(size_t count, size_t item_size);

#           ifdef __cplusplus

extern "C"

# endif

int ft_memcmp(const void *a, const void *b, size_t len);

#            ifdef __cplusplus

extern "C"

# endif

void *ft_memchr(const void *str, int to_find, size_t len);

#             ifdef __cplusplus

extern "C"

# endif

char *ft_strchr(const char *str, int to_find);

#              ifdef __cplusplus

extern "C"

# endif

char *ft_strrchr(const char *str, int to_find);

#               ifdef __cplusplus

extern "C"

# endif

size_t ft_strlen(const char *str);

#                ifdef __cplusplus

extern "C"

# endif

size_t ft_strlcpy(char *dest, char *source, size_t dest_size);

#                 ifdef __cplusplus

extern "C"

# endif

size_t ft_strlcat(char *dest, char *source, size_t dest_size);

#                  ifdef __cplusplus

extern "C"

# endif

int ft_strncmp(const char *a, const char *b, size_t len);

#                   ifdef __cplusplus

extern "C"

# endif

char *ft_strnstr(const char *str, const char *to_find, size_t len);

#                    ifdef __cplusplus

extern "C"

# endif

char *ft_strdup(const char *str);

#                     ifdef __cplusplus

extern "C"

# endif

int ft_toupper(int c);

#                      ifdef __cplusplus

extern "C"

# endif

int ft_tolower(int c);

#                       ifdef __cplusplus

extern "C"

# endif

int ft_atoi(const char *str);

// Part 2 - Additional functions

#                        ifdef __cplusplus

extern "C"

# endif

char *ft_substr(char const *str, unsigned int start, size_t len);

#                         ifdef __cplusplus

extern "C"

# endif

char *ft_strjoin(char const *prefix, char const *suffix);

#                          ifdef __cplusplus

extern "C"

# endif

char *ft_strtrim(char const *str, char const *ignore_set);

#                           ifdef __cplusplus

extern "C"

# endif

char **ft_split(char const *str, char c);

#                            ifdef __cplusplus

extern "C"

# endif

void ft_putchar_fd(char c, int fd);

#                             ifdef __cplusplus

extern "C"

# endif

void ft_putstr_fd(char *str, int fd);

#                              ifdef __cplusplus

extern "C"

# endif

void ft_putendl_fd(char *str, int fd);

#                               ifdef __cplusplus

extern "C"

# endif

void ft_putnbr_fd(int n, int fd);

#                                ifdef __cplusplus

extern "C"

# endif

char *ft_itoa(int n);

#                                 ifdef __cplusplus

extern "C"

# endif

void ft_striteri(char *str, void (*f)(unsigned int index, char *inout_c));

#                                  ifdef __cplusplus

extern "C"

# endif

char *ft_strmapi(char const *str, char (*f)(unsigned int index, char c));

#                                  endif
