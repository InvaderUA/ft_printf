/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:57:48 by klut              #+#    #+#             */
/*   Updated: 2016/12/22 21:13:53 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	short	i;

	d = (char*)dst;
	s = (char*)src;
	if (s > d)
		ft_memcpy(d, s, len);
	else
	{
		i = (short)len - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dst);
}
