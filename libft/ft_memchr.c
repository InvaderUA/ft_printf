/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:15:09 by klut              #+#    #+#             */
/*   Updated: 2016/12/22 20:41:39 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	if (n != 0)
	{
		while (n != 0)
		{
			if (*ps == (unsigned char)c)
				return ((void *)ps);
			ps++;
			n--;
		}
	}
	return (NULL);
}
