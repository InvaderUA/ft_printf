/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 05:31:26 by klut              #+#    #+#             */
/*   Updated: 2016/12/21 05:37:12 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*start;
	t_list	*next;

	start = *alst;
	while (start)
	{
		del(start->content, start->content_size);
		next = start->next;
		free(start);
		start = next;
	}
	(*alst) = NULL;
}
