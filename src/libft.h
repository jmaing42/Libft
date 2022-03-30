/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:39:25 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/30 14:13:50 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

// Part 1 - Libc functions
//  ft_part1_char.c
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
//  ft_part1_memory.c
void	ft_bzero(void *mem, size_t len);
void	*ft_memset(void *mem, int value, size_t len);
void	*ft_memcpy(void *dest, const void *source, size_t len);
void	*ft_memmove(void *dest, const void *source, size_t len);
void	*ft_calloc(size_t count, size_t item_size);
//  ft_part1_find.c
int		ft_memcmp(const void *a, const void *b, size_t len);
void	*ft_memchr(const void *str, int to_find, size_t len);
char	*ft_strchr(const char *str, int to_find);
char	*ft_strrchr(const char *str, int to_find);
//  ft_part1_string.c
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, char *source, size_t dest_size);
size_t	ft_strlcat(char *dest, char *source, size_t dest_size);
int		ft_strncmp(const char *a, const char *b, size_t len);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
//  ft_part1_etc.c
char	*ft_strdup(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);

// Part 2 = Additional functions
//  ft_part2_string.c
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *prefix, char const *suffix);
char	*ft_strtrim(char const *str, char const *ignore_set);
//  ft_part2_split.c
char	**ft_split(char const *str, char c);
//  ft_part2_print.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
//  ft_part2_etc.c
char	*ft_itoa(int n);
void	ft_striteri(char *str, void (*f)(unsigned int index, char *inout_c));
char	*ft_strmapi(char const *str, char (*f)(unsigned int index, char c));

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Part 3 - Singly Linked List
//  ft_part3_basic_bonus.c
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
//  ft_part3_advanced_bonus.c
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
