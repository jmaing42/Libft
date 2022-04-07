/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part3_basic_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:56:41 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/07 18:57:52 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *const	result = (t_list *) malloc(sizeof(t_list));

	if (!result)
		return (NULL);
	result->next = NULL;
	result->content = content;
	return (result);
}

void	ft_lstadd_front(t_list **lst, t_list *node)
{
	node->next = *lst;
	*lst = node;
}

int	ft_lstsize(t_list *lst)
{
	int	result;

	result = 0;
	while (lst)
	{
		result++;
		lst = lst->next;
	}
	return (result);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*result;

	result = lst;
	while (result && result->next)
		result = result -> next;
	return (result);
}

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	if (!*lst)
		*lst = node;
	else
		ft_lstlast(*lst)->next = node;
}
