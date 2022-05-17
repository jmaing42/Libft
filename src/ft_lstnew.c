/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:56:41 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 01:22:06 by Juyeong Maing    ###   ########.fr       */
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