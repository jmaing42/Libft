/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:03:16 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:21:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new_node;

	result = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		lst = lst->next;
		if (!new_node)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_node);
	}
	return (result);
}
