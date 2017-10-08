/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:51:49 by klut              #+#    #+#             */
/*   Updated: 2016/12/19 18:53:23 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (s1 != NULL && s2 != NULL)
	{
		ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (ptr != NULL)
		{
			ptr = ft_strcat(ptr, s1);
			ptr = ft_strcat(ptr, s2);
		}
		return (ptr);
	}
	return (NULL);
}
