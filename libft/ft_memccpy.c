/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:34:43 by klut              #+#    #+#             */
/*   Updated: 2016/12/11 13:45:30 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dest;
	char	*source;
	size_t	i;

	dest = (char*)dst;
	source = (char*)src;
	i = 0;
	while (n)
	{
		dest[i] = source[i];
		if (source[i] == c)
			return (&dest[i + 1]);
		i++;
		n--;
	}
	return (NULL);
}
