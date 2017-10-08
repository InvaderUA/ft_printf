/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 05:44:59 by klut              #+#    #+#             */
/*   Updated: 2016/12/21 05:48:32 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*start;

	if (!lst)
		return (NULL);
	new_list = f(lst);
	start = new_list;
	while (lst->next)
	{
		lst = lst->next;
		new_list->next = f(lst);
		new_list = new_list->next;
	}
	return (start);
}
