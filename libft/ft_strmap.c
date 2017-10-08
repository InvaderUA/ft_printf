/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:21:02 by klut              #+#    #+#             */
/*   Updated: 2016/12/20 18:24:51 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*c;
	char	s2;
	int		i;

	i = 0;
	if (s && f)
	{
		c = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!c)
			return (NULL);
		while (*s)
		{
			s2 = f(*s++);
			if (s2)
				c[i++] = s2;
		}
		c[i++] = '\0';
		return (c);
	}
	return (NULL);
}
