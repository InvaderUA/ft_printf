/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:48:47 by klut              #+#    #+#             */
/*   Updated: 2016/12/20 18:26:44 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	char			s2;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s && f)
	{
		c = (char*)malloc(ft_strlen(s) + 1);
		if (!c)
			return (NULL);
		while (s[i] != '\0')
		{
			s2 = s[i];
			if (f(i, s2))
				c[j++] = f(i, s[i]);
			i++;
		}
		c[j] = '\0';
		return (c);
	}
	return (NULL);
}
