/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:19:29 by klut              #+#    #+#             */
/*   Updated: 2016/12/20 15:39:30 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen((char *)s1) + 1;
	if (!(dest = (char *)ft_memalloc(len)))
		return (NULL);
	ft_strcpy((char *)dest, (char *)s1);
	return ((char *)dest);
}
