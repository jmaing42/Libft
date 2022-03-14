/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:39:25 by jmaing            #+#    #+#             */
/*   Updated: 2022/03/14 13:35:41 by jmaing           ###   ########.fr       */
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
void	*ft_memset(void *mem, int value, size_t len);
void	ft_bzero(void *mem, size_t len);
void	*ft_memcpy(void *dest, void *source, size_t len);
void	*ft_memmove(void *dest, void *source, size_t len);
size_t	ft_strlcpy(char *dest, char *source, size_t dest_size);
size_t	ft_strlcat(char *dest, char *source, size_t dest_size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int to_find);
char	*ft_strrchr(const char *str, int to_find);
int		ft_strncmp(const char *a, const char *b, size_t len);
void	*ft_memchr(const void *str, int to_find, size_t len);
int		ft_memcmp(const void *a, const void *b, size_t len);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t item_size);
char	*ft_strdup(const char *str);

char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *prefix, char const *suffix);
char	*ft_strtrim(char const *str, char const *ignore_set);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *str, char (*f)(unsigned int index, char c));
void	ft_striteri(char *str, void (*f)(unsigned int index, char *inout_c));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
